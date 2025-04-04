
void Quest::completeQuest( Player& player ) {
    cout << "任務完成：" << description << "！獲得獎勵 " << reward << " 金幣！" << endl;
    player.addMoney( reward );
} // end completeQuest()
