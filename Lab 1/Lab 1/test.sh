g++ -Wall -Werror -std=c++17 -g -DDEBUG *.cpp -o Lab2

echo Testing 1-80 cases...
echo File0:
./Lab2 2-80/input0.txt OutFiles/out0.txt
diff 2-80/answer0.txt OutFiles/out0.txt

echo File1:
./Lab2 2-80/input1.txt OutFiles/out1.txt
diff 2-80/answer1.txt OutFiles/out1.txt

echo File2:
./Lab2 2-80/input2.txt OutFiles/out2.txt
diff 2-80/answer2.txt OutFiles/out2.txt

echo File3:
./Lab2 2-80/input3.txt OutFiles/out3.txt
diff 2-80/answer3.txt OutFiles/out3.txt

echo File4:
./Lab2 2-80/input4.txt OutFiles/out4.txt
diff 2-80/answer4.txt OutFiles/out4.txt

echo File5:
./Lab2 2-80/input5.txt OutFiles/out5.txt
diff 2-80/answer5.txt OutFiles/out5.txt

echo File6:
./Lab2 2-80/input6.txt OutFiles/out6.txt
diff 2-80/answer6.txt OutFiles/out6.txt

echo File7:
./Lab2 2-80/input7.txt OutFiles/out7.txt
diff 2-80/answer7.txt OutFiles/out7.txt

echo File8:
./Lab2 2-80/input8.txt OutFiles/out8.txt
diff 2-80/answer8.txt OutFiles/out8.txt

echo Testing 1-100 cases...
echo File00:
./Lab2 2-100/input0.txt OutFiles/out00.txt
diff 2-100/answer0.txt OutFiles/out00.txt

echo File01:
./Lab2 2-100/input1.txt OutFiles/out01.txt
diff 2-100/answer1.txt OutFiles/out01.txt

echo File02:
./Lab2 2-100/input2.txt OutFiles/out02.txt
diff 2-100/answer2.txt OutFiles/out02.txt
echo Testing Complete!
