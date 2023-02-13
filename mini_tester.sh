
# 本家
<infile grep a1 | wc> outfile_sh

# 自作
./pipex infile "grep a1" "wc" outfile

# outを比較
diff -U 3 outfile_sh outfile && echo "OK" || echo "KO"
