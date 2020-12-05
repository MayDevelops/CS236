g++ -Wall -Werror -std=c++17 -g -DDEBUG *.cpp -o Lab4
echo -e "\033[1;34m--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"


echo -e "\033[1;33m Testing 4-80 Cases..."
echo -e "\033[1;31m File0:"
echo -e "\033[1;0m"
./Lab4 4-80/input0.txt > OutFiles/out0.txt
diff 4-80/answer0.txt OutFiles/out0.txt

echo -e "\033[1;31m File1:"
echo -e "\033[1;0m"
./Lab4 4-80/input1.txt > OutFiles/out1.txt
diff 4-80/answer1.txt OutFiles/out1.txt

echo -e "\033[1;31m File2:"
echo -e "\033[1;0m"
./Lab4 4-80/input2.txt > OutFiles/out2.txt
diff 4-80/answer2.txt OutFiles/out2.txt

echo -e "\033[1;31m File3:"
echo -e "\033[1;0m"
./Lab4 4-80/input3.txt > OutFiles/out3.txt
diff 4-80/answer3.txt OutFiles/out3.txt

echo -e "\033[1;31m File4:"
echo -e "\033[1;0m"
./Lab4 4-80/input4.txt > OutFiles/out4.txt
diff 4-80/answer4.txt OutFiles/out4.txt

echo -e "\033[1;31m File5:"
echo -e "\033[1;0m"
./Lab4 4-80/input5.txt > OutFiles/out5.txt
diff 4-80/answer5.txt OutFiles/out5.txt

echo -e "\033[1;31m File6:"
echo -e "\033[1;0m"
./Lab4 4-80/input6.txt > OutFiles/out6.txt
diff 4-80/answer6.txt OutFiles/out6.txt

echo -e "\033[1;31m File7:"
echo -e "\033[1;0m"
./Lab4 4-80/input7.txt > OutFiles/out7.txt
diff 4/answer7.txt OutFiles/out7.txt




echo -e "\033[1;33m Testing 4-100 Cases..."
echo -e "\033[1;31m File01:"
echo -e "\033[1;0m"
./Lab3 4-100/input1.txt > OutFiles/out01.txt
diff 4-100/answer1.txt OutFiles/out01.txt

echo -e "\033[1;31m File02:"
echo -e "\033[1;0m"
./Lab3 4-100/input2.txt > OutFiles/out02.txt
diff 4-100/answer2.txt OutFiles/out02.txt

echo -e "\033[1;31m File03:"
echo -e "\033[1;0m"
./Lab3 4-100/input3.txt > OutFiles/out03.txt
diff 4-100/answer3.txt OutFiles/out03.txt
echo -e "\033[1;31m File05:"
echo -e "\033[1;0m"
./Lab3 4-100/input5.txt > OutFiles/out05.txt
diff 4-100/answer5.txt OutFiles/out05.txt

echo -e "\033[1;31m File06:"
echo -e "\033[1;0m"
./Lab3 4-100/input6.txt > OutFiles/out06.txt
diff 4-100/answer6.txt OutFiles/out06.txt

echo -e "\033[1;31m File07:"
echo -e "\033[1;0m"
./Lab3 4-100/input7.txt > OutFiles/out07.txt
diff 4-100/answer7.txt OutFiles/out07.txt

echo -e "\033[1;31m File08:"
echo -e "\033[1;0m"
./Lab3 4-100/input8.txt > OutFiles/out08.txt
diff 4-100/answer8.txt OutFiles/out08.txt
echo -e "\033[1;32m Testing Complete!"

rm ./Lab4
