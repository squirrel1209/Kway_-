
void Quest::completeQuest( Player& player ) {
    cout << "���ȧ����G" << description << "�I��o���y " << reward << " �����I" << endl;
    player.addMoney( reward );
} // end completeQuest()
