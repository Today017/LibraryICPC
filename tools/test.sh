#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <solution_file.cpp>"
    exit 1
fi

SOLUTION_FILE=$1

rm ./test/*.txt

# コンパイル
g++ ./test/generate.cpp -o ./test/generate_testcase -std=c++17 -O2
g++ ./test/naive.cpp -o ./test/naive -std=c++17 -O2
g++ $SOLUTION_FILE -std=c++17 -O2

echo -e "\033[32mCompiled!\033[0m"


L=100

if [ $# -eq 2 ]; then
    L=$2
fi


# テストケースの生成
for i in $(seq 0 $((L-1))); do
    ./test/generate_testcase > "./test/input${i}.txt"
done

echo -e "\033[32mGenerated testcases!\033[0m"

# ナイーブ解法の出力生成
for i in $(seq 0 $((L-1))); do
    # "\r"で進行状況を表示
    echo -ne "Generating naive outputs... $i/100\r"

    ./test/naive < "./test/input${i}.txt" > "./test/output${i}.txt"
done

echo -e "\033[32mGenerated naive outputs!\033[0m"

# 自分の解法の出力生成
for i in $(seq 0 $((L-1))); do
    echo -ne "Generating solve outputs... $i/100\r"

    ./a.out < "./test/input${i}.txt" > "./test/solve${i}.txt"
done

echo -e "\033[32mGenerated solve outputs!\033[0m"


# 結果の比較
for i in $(seq 0 $((L-1))); do
    if ! diff "./test/solve${i}.txt" "./test/output${i}.txt" > /dev/null; then
        echo -e "\033[31mTestcase $i Failed!\033[0m"
        cat "./test/input${i}.txt"
        echo -e "\033[32mCorrect Output:\033[0m"
        cat "./test/output${i}.txt"
        echo -e "\033[31mYour Output:\033[0m"
        cat "./test/solve${i}.txt"
        echo "----------------------------------------"
    fi
done
