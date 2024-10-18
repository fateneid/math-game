#include <iostream>
#include <cstdlib>
using namespace std;

struct stReadInfo {
	int NumberOfTimes = 0, QuestionsLevel = 0, OperationType = 0, RightAnswers = 0, WrongAnswers = 0;
};

int ReadNumberInRange(int From, int To, string Message, string Space) {
	int Number;
	do {
		cout << Message << Space;
		cin >> Number;
	} while (Number < From || Number > To);
	return Number;
}

int RandomNumberInRange(int From, int To) {
	int RandomNumber = rand() % (To + 1 - From) + From;
	return RandomNumber;
}

void ReadData(stReadInfo& ReadInfo) {
	ReadInfo.NumberOfTimes = ReadNumberInRange(1, 100, "How Many Questions do you want to answer ?", " ");
	ReadInfo.QuestionsLevel = ReadNumberInRange(1, 4, "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?", " ");
	ReadInfo.OperationType = ReadNumberInRange(1, 5, "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?", " ");
}

char SetOperation(int TypeChoice) {

	char OperationArray[4] = { '+','-','x','/' };

	if (TypeChoice == 5) {
		return OperationArray[RandomNumberInRange(1, 4) - 1];
	}
	else {
		return OperationArray[TypeChoice - 1];
	}

}

string SetLevel(int LevelChoice) {
	string LevelArray[3] = { "Easy","Med","Hard" };

	if (LevelChoice == 4) {
		return LevelArray[RandomNumberInRange(1, 3) - 1];
	}
	else {
		return LevelArray[LevelChoice - 1];
	}
}

int RandomNumberToCalculate(string LevelChoice) {
	if (LevelChoice == "Easy")
		return RandomNumberInRange(1, 10);
	else if (LevelChoice == "Med")
		return RandomNumberInRange(11, 49);
	else
		return RandomNumberInRange(50, 100);
}

int CorrectAnswer(int FirstNum, int SecondNum, char Operation) {

	switch (Operation) {
	case '+':
		return FirstNum + SecondNum;
		break;
	case '-':
		return FirstNum - SecondNum;
		break;
	case 'x':
		return FirstNum * SecondNum;
		break;
	case '/':
		return FirstNum / SecondNum;
		break;
	}
}

void ResultOfRound(int PlayerAnswer, int CorrectAnswer, bool& Flag) {
	if (PlayerAnswer == CorrectAnswer) {
		system("color AF");
		cout << "Right Answer :-)\n\n";
		Flag = true;
	}
	else {
		system("color 4F");
		cout << "Wrong Answer :-(\n";
		cout << "The right answer is: " << CorrectAnswer << "\n\n";
		Flag = false;
	}

}

string PassOrFail(stReadInfo ReadInfo) {

	if (ReadInfo.RightAnswers >= ReadInfo.WrongAnswers)
		return "PASS :-)";
	else
		return "Fail:-(";
}

string GetLevelName(int QuestionsLevel) {
	if (QuestionsLevel == 4) {
		return "Mix";
	}
	else {
		return SetLevel(QuestionsLevel);
	}
}

string GetOperationName(int OperationType) {
	string OpTypeArray[5] = { "Add","Sub", "Mul", "Div","Mix" };
	return OpTypeArray[OperationType - 1];
}

void PrintFinalResult(stReadInfo ReadInfo) {

	cout << "\n_______________________________\n\n";
	cout << " Final Results is " << PassOrFail(ReadInfo);
	cout << "\n_______________________________\n\n";
	cout << "Number of Questions: " << ReadInfo.NumberOfTimes << endl;
	cout << "Questions Level: " << GetLevelName(ReadInfo.QuestionsLevel) << endl;
	cout << "OpType: " << GetOperationName(ReadInfo.OperationType) << endl;
	cout << "Number of Right Answers: " << ReadInfo.RightAnswers << endl;
	cout << "Number of Wrong Answers: " << ReadInfo.WrongAnswers;
	cout << "\n_______________________________\n\n";

}

void ResetScreen() {
	system("cls");
	system("color 0F");
}

void PlayMathGame() {
	stReadInfo ReadInfo;
	int Answer, FirstNum, SecondNum, GetCorrectAnswer;
	char Operation;
	string Level;
	bool Flag;

	ReadData(ReadInfo);
	cout << "\n";
	for (int i = 1; i <= ReadInfo.NumberOfTimes; i++) {
		cout << "Question  [" << i << "/" << ReadInfo.NumberOfTimes << "]" << "\n\n";

		Level = SetLevel(ReadInfo.QuestionsLevel);
		Operation = SetOperation(ReadInfo.OperationType);
		FirstNum = RandomNumberToCalculate(Level);
		SecondNum = RandomNumberToCalculate(Level);
		if (Operation == '/' && SecondNum == 0) {
			SecondNum = 1;
		}

		cout << FirstNum << "\n";
		cout << SecondNum << " " << Operation << "\n";
		cout << "____________\n";
		cin >> Answer;
		GetCorrectAnswer = CorrectAnswer(FirstNum, SecondNum, Operation);
		ResultOfRound(Answer, GetCorrectAnswer, Flag);
		if (Flag == true) {
			ReadInfo.RightAnswers++;
		}
		else {
			ReadInfo.WrongAnswers++;
		}
	}
	PrintFinalResult(ReadInfo);

}

void StartGame() {
	char PlayAgain;
	do {
		ResetScreen();
		PlayMathGame();
		cout << "\nDo you want to play again? Y/N?" << " ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();


	return 0;
}
/*
Read number from the user to be the amount of qestion
Read number from the user to be the qestion level
Read number from the user to be the opt type

random function


final result

*/

/*
1:10 easy
11:49 mid
50:100 hard
*/

/*
number of questions
questions level
OpType
Number of rigth answers
Number of wrong answers
*/