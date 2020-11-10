g++ -Wall -Werror -std=c++17 -g -DDEBUG *.cpp -o Lab3
echo -e "\033[1;34m--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"


echo -e "\033[1;33m Testing 3-80 Cases..."
echo -e "\033[1;31m File0:"
echo -e "\033[1;0m"
./Lab3 3-80/input0.txt > OutFiles/out0.txt
diff 3-80/answer0.txt OutFiles/out0.txt

echo -e "\033[1;31m File1:"
echo -e "\033[1;0m"
./Lab3 3-80/input1.txt > OutFiles/out1.txt
diff 3-80/answer1.txt OutFiles/out1.txt

echo -e "\033[1;31m File2:"
echo -e "\033[1;0m"
./Lab3 3-80/input2.txt > OutFiles/out2.txt
diff 3-80/answer2.txt OutFiles/out2.txt

echo -e "\033[1;31m File3:"
echo -e "\033[1;0m"
./Lab3 3-80/input3.txt > OutFiles/out3.txt
diff 3-80/answer3.txt OutFiles/out3.txt

echo -e "\033[1;31m File4:"
echo -e "\033[1;0m"
./Lab3 3-80/input4.txt > OutFiles/out4.txt
diff 3-80/answer4.txt OutFiles/out4.txt

echo -e "\033[1;31m File7:"
echo -e "\033[1;0m"
./Lab3 3-80/input7.txt > OutFiles/out7.txt
diff 3-80/answer7.txt OutFiles/out7.txt

echo -e "\033[1;31m File8:"
echo -e "\033[1;0m"
./Lab3 3-80/input8.txt > OutFiles/out8.txt
diff 3-80/answer8.txt OutFiles/out8.txt

echo -e "\033[1;33m Testing 3-100 Cases..."
echo -e "\033[1;31m File05:"
echo -e "\033[1;0m"
./Lab3 3-100/input5.txt > OutFiles/out05.txt
diff 3-100/answer5.txt OutFiles/out05.txt

echo -e "\033[1;31m File06:"
echo -e "\033[1;0m"
./Lab3 3-100/input6.txt > OutFiles/out06.txt
diff 3-100/answer6.txt OutFiles/out06.txt

echo -e "\033[1;31m File09:"
echo -e "\033[1;0m"
./Lab3 3-100/input9.txt > OutFiles/out09.txt
diff 3-100/answer9.txt OutFiles/out09.txt
echo -e "\033[1;32m Testing Complete!"

rm ./Lab3
