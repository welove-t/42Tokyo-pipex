#!/bin/sh

#---- 通常ケース ----#
# 本家
<infile grep a1 | wc> outfile_sh

# 自作
../pipex infile "grep a1" "wc" outfile

# outを比較
/bin/echo -n '1:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"


#----2 infile NULLケース ----#
# 本家
<infile_2_n grep a1 | wc> outfile_sh

# 自作
../pipex infile_2_n "grep a1" "wc" outfile

# outを比較
/bin/echo -n '2:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"

#----3 infile 未使用ケース ----#
# 本家
< infile_3_nouse ls -l | wc -l > outfile_sh

# 自作
../pipex infile_3_nouse "ls -l" "wc -l" outfile

# outを比較
/bin/echo -n '3:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"


#----4 infileが標準入力 ケース ----#
# 本家
< /dev/stdin cat | ls > outfile_sh

# 自作
../pipex /dev/stdin cat ls outfile

# outを比較
/bin/echo -n '4:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"

#----5 infileが大きい ケース ----#
# 本家
< infile_5_bigsize cat | cat > outfile_sh

# 自作
../pipex infile_5_bigsize "cat" "cat" outfile

# outを比較
/bin/echo -n '5:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"
