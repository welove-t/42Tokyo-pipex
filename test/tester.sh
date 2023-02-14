#!/bin/sh

## 通常ケース
# 本家
<infile grep a1 | wc> outfile_sh

# 自作
../pipex infile "grep a1" "wc" outfile

# outを比較
/bin/echo -n '1:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"


## infile NULLケース
# 本家
<infile_n grep a1 | wc> outfile_sh

# 自作
../pipex infile_n "grep a1" "wc" outfile

# outを比較
/bin/echo -n '2:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"
