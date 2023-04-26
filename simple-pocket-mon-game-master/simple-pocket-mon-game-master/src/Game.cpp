/*
* April 30, 2018 - Made by KeonHeeLee :: https://github.com/KeonHeeLee/simple-pocket-mon-game
* I want to refer this repositoy to understand FA (Finite Automata).
* Thanks to remain this comment if you would use or refer this repository's source code.
*/

#include "Game.h"

Game::Game() {
	this->myPocketMon = PocketMon(1000, 50, 20, "��ī��");
	this->myPocketMon.setSkillSet(skill(80, "���� ��ġ��"));
	this->myPocketMon.setSkillSet(skill(200, "�鸸��Ʈ"));

	this->com = PocketMon(1000, 30, 50, "���̸�");
	this->com.setSkillSet(skill(60, "���� ��ġ��"));
	this->com.setSkillSet(skill(220, "�Ҳ� ����"));

	this->originalComHP = this->com.getHP();
}

void Game::print_select(){
	cout << endl << "�÷��̾� �� : " << endl;
	cout << "- 0.���� ��ġ��" << endl << "- 1.�鸸��Ʈ " << endl << "- 2.�⺻����" << endl << "- 3.����" << endl << "�����Ͻʽÿ�. >> ";
}

void Game::run_skill(char *user_name, char *skill_name){
	cout << user_name << "��(��) " << skill_name << "��(��) �����ߴ�." << endl;
}

void Game::print_game_over(){
	cout << endl;
	cout << "**************************" << endl;
	cout << "**       GAME OVER      **" << endl;
	cout << "**************************" << endl;
}

void Game::print_victory(){
	cout << endl;
	cout << "**************************" << endl;
	cout << "**        VICTORY       **" << endl;
	cout << "**************************" << endl;
}

void Game::run(){
	srand((unsigned int)time(NULL));
	/********************************************************* Start Game Loop ************************************************************/

	while (this->com.getHP()){
		int status;
		int user_damage;
		int com_damage;

		print_select();
		cin >> status;

		if (status == 3) {
			cout << "�÷��̾ ������ ����." << endl;
			print_game_over();
			break;
		}
		else if (status == 0){
			run_skill(this->myPocketMon.getName(), this->myPocketMon.get_skillset().at(status).get_skill_name());
			user_damage = this->myPocketMon.get_skillset().at(status).get_damage();
		}
		else if (status == 1){
			if (pika_01_cnt != 0){
				run_skill(this->myPocketMon.getName(), this->myPocketMon.get_skillset().at(status).get_skill_name());
				user_damage = this->myPocketMon.get_skillset().at(status).get_damage();
				pika_01_cnt--;
			}
			else {
				cout << this->myPocketMon.getName() << "��(��) " << this->myPocketMon.get_skillset().at(status).get_skill_name() << "�� �����Ͽ�����, ������ �����ߴ�." << endl;
				user_damage = this->myPocketMon.getDamage();
				cout << this->myPocketMon.getName() << "��(��) �⺻ ������ �����ߴ�." << endl;
			}
		}
		else if (status == 2){
			cout << this->myPocketMon.getName() << "��(��) �⺻������ �����ߴ�." << endl;
			user_damage = this->myPocketMon.getDamage();
		}
		/************************************************************ ~ User Phase ********************************************************************************/

		random = rand() % 100 + 1;

		if (random <= this->com.getAvoid()) {
			tempComHP = this->com.getHP();
			cout << "������, " << this->com.getName() << "��(��) ���ߴ�." << endl;
		}
		else {
			tempComHP = this->com.getDamageByUser(user_damage);
			cout << this->com.getName() << "��(��) " << user_damage << "�� �������� �޾Ҵ�!" << endl;
		}

		cout << "COM : " << "HP - " << this->com.getHP() << endl;
		if (tempComHP <= 0){
			cout << this->com.getName() << "��(��) ������!!" << endl;
			print_victory();
			break;
		}
		/************************************************************ ~ User Result Phase ************************************************************************/

		cout << endl << "��ǻ���� ���� �Դ�." << endl;
		float current_com_HP = (float)tempComHP / originalComHP;

		if (current_com_HP < 0.1){
			int avoidField = rand() % 2;
			if (avoidField == 1){
				cout << "������, " << this->com.getName() << "��(��) �����ƴ�." << endl;
				print_victory();
				break;
			}
		}

		random = rand() % 100 + 1;

		if (current_com_HP <= 0.5){
			com_skill_set = rand() % 2;
			cout << this->com.getName() << "��(��) �ݰ��� �Ͽ���." << endl;

			if (com_skill_set == 1 && char_01_cnt != 0){
				run_skill(this->com.getName(), this->com.get_skillset().at(com_skill_set).get_skill_name());
				com_damage = this->com.get_skillset().at(com_skill_set).get_damage();
				char_01_cnt--;
			}
			else if (com_skill_set == 0 || char_01_cnt == 0){
				run_skill(this->com.getName(), this->com.get_skillset().at(com_skill_set).get_skill_name());
				com_damage = this->com.get_skillset().at(com_skill_set).get_damage();
			}
		}
		else {
			com_skill_set = rand() % 2;
			if (com_skill_set == 1) {
				cout << this->com.getName() << "�� �Ϲݰ���!" << endl;
				com_damage = this->com.getDamage();
			}
			else if (com_skill_set == 0) {
				run_skill(this->com.getName(), this->com.get_skillset().at(com_skill_set).get_skill_name());
				com_damage = this->com.get_skillset().at(com_skill_set).get_damage();
			}
		}
		if (random <= this->myPocketMon.getAvoid())
			cout << this->myPocketMon.getName() << "��(��) ������ ���ߴ�." << endl;
		else {
			this->myPocketMon.getDamageByUser(com_damage);
			cout << this->myPocketMon.getName() << "��(��) " << com_damage << "�� �������� �Ծ���." << endl;
		}

		cout << "USER: " << "HP - " << this->myPocketMon.getHP() << endl;

		/************************************************************* ~ Computer Phase ******************************************************************/

		if (this->myPocketMon.getHP() <= 0){
			cout << this->myPocketMon.getName() << "��(��) ������!!" << endl << endl;
			print_game_over();
			break;
		}

		cout << "**************************" << endl;
		/************************************************************* ~ Computer Result Phase **********************************************************/
	}
}
