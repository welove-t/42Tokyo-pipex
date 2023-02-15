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
<infile_2_blank grep a1 | wc> outfile_sh

# 自作
../pipex infile_2_blank "grep a1" "wc" outfile

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

#----6 cmdが絶対パス ケース ----#
# 本家
< infile_6_blank /bin/ls -1 | cat > outfile_sh

# 自作
../pipex infile_6_blank "/bin/ls -1" "cat" outfile

# outを比較
/bin/echo -n '6:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"

#----7 自作cmd ケース ----#
# # 本家
# < infile ./echo7.sh | cat > outfile_sh

# # 自作
# ../pipex infile "./echo7.sh" "cat" outfile

# # outを比較
# /bin/echo -n '7:'
# diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"

#----8 存在しないコマンド　ケース ----#
# 本家
<infile hoge | echo test8> outfile_sh

# 自作
../pipex infile "hoge" "echo test8" outfile

# outを比較
/bin/echo -n '8:'
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"
