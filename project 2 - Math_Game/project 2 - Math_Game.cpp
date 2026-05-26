#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;



enum enQuestionLevel { easy = 1, med = 2, hard = 3, mixLevel = 4 };
enum enOperationType { add = 1, sub = 2, mul = 3, DivOP = 4, MixOperation = 5 };//غيرت القسمة و الميكس لانه هاذي دوال جاهزة في س بلس بلس ف عشان مايتخربط الكومبايلر غيرت اساميهم
enum enPassOrFailed { Pass = 1, Faild = 2 ,Draw =3};

struct stQuestion
{
    int FirstNumber = 0;
    int SecondNumber = 0;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    int PlayerAnswer;
    int CorrectAnswer;
};
struct stQuizz
{
    int NumberOfQuestion;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    int RightAnswers;
    int WrongAnswers;
    enPassOrFailed PassOrNot;
};

int RandomNumber(int from,int to)
{
    return rand() % (to - from + 1) + from;
} 

int ReadHowManyQuestion()
{
    int number = 1;

    do
    {
        cout << "how many Question do you want to play? ( 1 to 20 )";
        cin >> number;
    } while (number < 1 || number > 20);

    return number;
}

int ReadQuestionLevel()
{
    int number = 0;

    do
    {
        cout << "pls enter Question level ([1] Easy , [2] Med, [3] Hard , [4] Mix) ?";
        cin >> number;
    } while (number < 1 || number > 4);

    return number;
}

int ReadOperationType()
{
    int number = 0;

    do
    {
        cout << "pls enter Operation Type ([1] Add , [2] Sub, [3] Mul , [4] Div , [5] Mix) ?";
        cin >> number;
    } while (number < 1 || number > 5);

    return number;
}

stQuestion GenerateQuestion(enOperationType OperationType, enQuestionLevel QuestionLevel)
{
    stQuestion Questions;

    if (QuestionLevel == enQuestionLevel::mixLevel)
    {
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
    }

    Questions.QuestionLevel = QuestionLevel;

    switch (QuestionLevel)
    {
    case enQuestionLevel::easy:
        Questions.FirstNumber = RandomNumber(1, 10);
        Questions.SecondNumber = RandomNumber(1, 10);
        break;
    case enQuestionLevel::med:
        Questions.FirstNumber = RandomNumber(10, 100);
        Questions.SecondNumber = RandomNumber(10, 100);
        break;
    case enQuestionLevel::hard:
        Questions.FirstNumber = RandomNumber(100, 999);
        Questions.SecondNumber = RandomNumber(100, 999);
        break;
    }


    if (OperationType == enOperationType::MixOperation)
    {
        OperationType = (enOperationType)RandomNumber(1, 4);
    }

    Questions.OperationType = OperationType;

    switch (OperationType)
    {
    case enOperationType::add:
        Questions.CorrectAnswer = Questions.FirstNumber + Questions.SecondNumber;
        break;
    case enOperationType::sub:
        Questions.CorrectAnswer = Questions.FirstNumber - Questions.SecondNumber;
        break;
    case enOperationType::mul:
        Questions.CorrectAnswer = Questions.FirstNumber * Questions.SecondNumber;
        break;
    case enOperationType::DivOP:
        Questions.CorrectAnswer = Questions.FirstNumber / Questions.SecondNumber;
        break;
    }

    return Questions;
}

char GetOperationType(enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::add:
        return '+';
    case enOperationType::sub:
        return '-';
    case enOperationType::mul:
        return '*';
        case enOperationType::DivOP:
        return '/';
    case enOperationType::MixOperation:
        return 'M';
    }
}

string GetLevelType(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
        case enQuestionLevel::easy:
        return "Easy";
        case enQuestionLevel::med:
        return "Med";
        case enQuestionLevel::hard:
        return "Hard";
        case enQuestionLevel::mixLevel:
        return "Mix";
    }
}

void PrintAndReadQuestion(stQuestion &Question)
{
        cout << Question.FirstNumber << " " << GetOperationType(Question.OperationType) << " " << Question.SecondNumber << " = ";
        cin >> Question.PlayerAnswer;
}

int CheckIfRightorNot(stQuestion Question)
{
    if (Question.CorrectAnswer == Question.PlayerAnswer)
    {
        system("color 2F");
        cout << "Right Answer!" << endl;
        return true;
    }
    else
    {
        cout << "\a";
        system("color 4F");
        cout << "Wrong Answer" << endl;
        cout << "the right answer is : " << Question.CorrectAnswer << endl;
        return false;
    }
}

stQuizz PlayQuizz()
{
    int numberofround = ReadHowManyQuestion();
    int numberoflevel = ReadQuestionLevel();
   int numberofoperationType = ReadOperationType();


   stQuizz QuizzResults =
   {
       0,(enQuestionLevel)numberoflevel,(enOperationType)numberofoperationType,0,0,enPassOrFailed::Faild
   };

   QuizzResults.NumberOfQuestion = numberofround;

    for (int i = 1; i <= numberofround; i++)
    {
        system("color 0F");
        cout << "Question [ " << i << "/" << numberofround << " ]" << endl;
        stQuestion Question = GenerateQuestion((enOperationType)numberofoperationType,(enQuestionLevel)numberoflevel);
        PrintAndReadQuestion(Question);
        
        if (CheckIfRightorNot(Question))
        {
            ++QuizzResults.RightAnswers;
        }
        else
        {
            ++QuizzResults.WrongAnswers;
        }
    }

    if (QuizzResults.RightAnswers > (QuizzResults.NumberOfQuestion / 2))
    {
        QuizzResults.PassOrNot = enPassOrFailed::Pass;
    }
    else if (QuizzResults.RightAnswers < QuizzResults.WrongAnswers)
    {
        QuizzResults.PassOrNot = enPassOrFailed::Faild;
    }
    else if (QuizzResults.RightAnswers == QuizzResults.WrongAnswers)
    {
        QuizzResults.PassOrNot = enPassOrFailed::Draw;
    }

    return QuizzResults;
}

string Tabs(int HowmanyTabs)
{
    string t = "";

    for (int i = 0; i < HowmanyTabs; i++)
    {
        t += "\t";
    }

    return t;
}

void PrintQuizResults(stQuizz QuizzResults)
{
    cout << Tabs(1) << "____________________________________________________" << endl;
    if (QuizzResults.PassOrNot == enPassOrFailed::Pass)
    {
        cout << "                                      Pass :)" << endl;
        system("color 2F");
    }
    else if (QuizzResults.PassOrNot == enPassOrFailed::Draw)
    {
        cout << "                                      Draw" << endl;
        system("color 6F");
    }
    else
    {
        cout << "                                      faild (:" << endl;
        system("color 4F");
        cout << "\a";
    }
    cout << Tabs(1) << "_____________________________________________________" << endl;
   

    cout << Tabs(1) << "The number of Questions is : " << QuizzResults.NumberOfQuestion << endl;
    cout << Tabs(1) << "Question level : " << GetLevelType(QuizzResults.QuestionLevel) << endl;
    cout << Tabs(1) << "OperationType is : " << GetOperationType(QuizzResults.OperationType) <<  endl;
    cout << Tabs(1) << "the number of Right answer is : " << QuizzResults.RightAnswers << endl;
    cout << Tabs(1) << "the number of wrong answer is : " << QuizzResults.WrongAnswers << endl;
    cout << Tabs(1) << "_____________________________________________________" << endl;
}

void ResetGame()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char more = 'y';

    do
    {
        ResetGame();
        stQuizz QuizzResult = PlayQuizz();
        PrintQuizResults(QuizzResult);
        cout << Tabs(1) << "do you want to play again? (Y/N)";
        cin >> more;
    } while (more == 'y' || more == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));


    StartGame();


    return 0;
}