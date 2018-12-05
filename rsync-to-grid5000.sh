#!/bin/bash

rsync -e ssh -avz --exclude-from=".gitignore" . plefebvre@access.grid5000.fr:grenoble/INSA-5IF/Sema31/TD-1-OpenMP
