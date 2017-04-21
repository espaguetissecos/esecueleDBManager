#!/bin/bash

COMMAND="valgrind --leak-check=full dist/Debug/GNU-Linux-x86/esecuele"

rm -rf bank_db

$COMMAND createdb bank_db

$COMMAND define bank_db << EOF
TABLE clients 2 INT STR
TABLE accounts 3 INT STR INT
TABLE accounts_clients 2 INT INT
INDEX i_clients clients 0
INDEX i_accounts accounts 0
INDEX i_accounts_clients_0 accounts_clients 0
INDEX i_accounts_clients_1 accounts_clients 1
EOF

$COMMAND insert bank_db << EOF
COPY clients ../bank_files/clients.txt
COPY accounts ../bank_files/accounts.txt
COPY accounts_clients ../bank_files/accounts_clients.txt
EOF

# Test the following queries:
# - Which are the accounts of the Brooklyn branch? Show account_id and amount
$COMMAND query bank_db << EOF
accounts SEQUENTIAL 1 STR Brooklyn C_COLEQCTE SELECT INT 0 P_COL INT 2 P_COL 2 PROJECT
EOF
# - Who owns an account in the Queens branch? Show account number, amount and the name of the owner
$COMMAND query bank_db << EOF
accounts SEQUENTIAL 1 STR Queens C_COLEQCTE SELECT INT 0 P_COL INT 2 P_COL 2 PROJECT accounts_clients SEQUENTIAL PRODUCT 0 2 C_COLEQCOL SELECT INT 0 P_COL INT 1 P_COL INT 3 P_COL 3 PROJECT clients SEQUENTIAL PRODUCT 2 3 C_COLEQCOL SELECT INT 0 P_COL INT 1 P_COL STR 4 P_COL 3 PROJECT
EOF

#$COMMAND query bank_db
