#include "QuestSystem.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <cstdlib>

Question::Question() : questionDescription("無題目"), answer(-1) {} //預設的建構函數
Question::Question(const std::string& questionDescription,int answer):questionDescription(questionDescription),answer(answer){}
Quest::Quest(std::string description, int reward, std::vector<Question> questionList)
    : description(description), reward(reward), complete(false), progress(0), questionList(questionList){ //帶參數的
        generateRandomQuestion();         //將原本在建構函數內部的隨機題目邏輯，封裝到 generateRandomQuestion() 中呼叫
        /*if (!questionList.empty()) {
            int questionIndex = rand() % questionList.size();
            randomQuestion = questionList[questionIndex];  // 隨機選擇一題
        } else {
            randomQuestion = Question("無題目", -1);  // 如果題目列表是空的，設定無題目
        }*/
}
void Quest::generateRandomQuestion(){
    if(!questionList.empty()){
        int questionIndex = rand() % questionList.size();  // 隨機選擇一題
        randomQuestion = questionList[questionIndex];
    }else{
        randomQuestion = Question("無題目",-1);         // 如果題目列表是空的，設定無題目
    }
}
void Quest::completeQuest(Character& player) {     //任務完成時獲得獎勵  
    if(!complete){
        std::cout<<"尚未完成任務"<<std::endl;   
        return;
}
    std::cout << "任務完成：" << description << "，獲得獎勵： " << reward << " 金幣" << std::endl;
    player.addMoney( reward );
} // end completeQuest()
std::string Quest::getDescription() const{         //取得任務描述
    return description;
}
int Quest::getReward() const{                 //取得任務獎勵  
    return reward;
}
void Quest::updateProgress(int answer) {             //更新任務進度
    if(!complete) {
        if (answer == randomQuestion.getAnswer()) {  // 比對玩家的答案
            complete = true;  // 答對即完成任務
            std::cout << "你答對了！恭喜完成任務" << std::endl;
        } else {
            std::cout << "回答錯誤，再試一次" << std::endl;
        }
    }

}
bool Quest::isComplete() const{          //檢查任務是否完成
    return complete;
}
std::string Question::getDescription() const{     //取得問題描述
    return questionDescription;
}
int Question::getAnswer() const{             //取得問題正確答案
    return answer;
}
Question Quest::getCurrentQuestion() const{   //取得當前隨機題目
    return randomQuestion;
    //return question;
}



void startQuest(Character& player)
{
    std::vector<Question> questionPool = {
        Question("1 + 1 = ?", 2),
        Question("3 * 3 = ?", 9),
        Question("10 - 4 = ?", 6),
        Question("5 + 7 = ?", 12),
        Question("8 / 2 = ?", 4)
    };

    Quest quest("", 0, questionPool);
    bool questAccepted = false;

    bool exitQuest=false;
    int choice;
    while (!exitQuest) {
        std::cout << "=========任務系統=========" << std::endl;
        std::cout << "[1]顯示玩家狀態" << std::endl;
        std::cout << "[2]接取任務" << std::endl;
        std::cout << "[3]前往答題" << std::endl;
        std::cout << "[4]提交任務" << std::endl;
        std::cout << "[5]離開" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << "你接下來要......." << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                player.showStatus();
                break;

            case 2:
                system("cls");
                if (!questAccepted) {
                    player.AcceptQuest(quest);
                    quest = Quest(" 「解答一題數學題」 ", 100, questionPool);
                    std::cout << "你接取了任務" << quest.getDescription() << std::endl;
                    questAccepted = true;
                } else {
                    std::cout << "你已接取任務，請先完成!" << std::endl;
                }
                break;

            case 3:
                system("cls");
                if (!questAccepted) {
                    std::cout << "請先前往接取任務" << std::endl;
                    break;
                }
                if (quest.isComplete()) {
                    std::cout << "你已完成任務，請前往提交" << std::endl;
                } else {
                    std::cout << "題目：" << std::endl;
                    std::cout << quest.getCurrentQuestion().getDescription() << std::endl;
                    std::cout << "請輸入答案：";
                    int ans;
                    std::cin >> ans;
                    quest.updateProgress(ans);
                }
                break;

            case 4:
                system("cls");
                if (!questAccepted) {
                    std::cout << "你還未接取任務" << std::endl;
                    break;
                }
                if (quest.isComplete()) {
                    quest.completeQuest(player);
                    //filedata.savePlayerData(player);  // 完成任務後儲存 squirrel 的新狀態
                    questAccepted = false;
                } else {
                    std::cout << "任務未完成，無法提交，請先完成任務吧" << std::endl;
                }
                break;

            case 5:
                system("cls");
                std::cout << "你已離開任務系統" << std::endl;
                exitQuest=true;
                break;

            default:
                system("cls");
                std::cout << "無效的操作，請重新輸入" << std::endl;
                break;
        }
    }
}