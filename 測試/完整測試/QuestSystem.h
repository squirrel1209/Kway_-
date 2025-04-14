#ifndef QUESTSYSTEM_H
#define QUESTSYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>


class Character;


void startQuest(Character& player);


class Question{
private:
    int answer;  //正確答案
    std::string questionDescription; //問題描述
public:
    Question();   //預設建構子
    Question(const std::string& questionDescription,int answer);  //帶參數建構子
    std::string getDescription() const;   //取得題目描述
    int getAnswer() const;                //取得正確答案
};
                    

class Quest {
private:
    //Question question;
    std::string description;            //任務描述
    int reward;                         //獎勵 
    int progress = 0 ;                  //任務進度
    bool complete = false;              //任務是否完成   
    std::vector<Question> questionList; //問題題庫 
    Question randomQuestion;            //隨機出的問題


public:
    Quest( std::string description, int reward, std::vector<Question> questionList); //帶參數的建構子
    Question getCurrentQuestion() const;                                        //取得任務題目
    void generateRandomQuestion();                                              //取得題庫隨機出的題目    
    void completeQuest( Character& player );                                       //提交任務並發獎勵
    std::string getDescription() const;                                              //取得任務描述
    int getReward() const;                                                      //取得任務獎勵 
    void updateProgress(int answer);                                            //取得任務更新進度
    bool isComplete() const;                                                    //檢查任務是否完成
    

};
#endif // QUESTSYSTEM_H
