/*
* April 30, 2018 - Made by KeonHeeLee :: https://github.com/KeonHeeLee/simple-pocket-mon-game
* I want to refer this repositoy to understand FA (Finite Automata).
* Thanks to remain this comment if you would use or refer this repository's source code.
*/

#include "Game.h"

Game::Game() {
	this->myPocketMon = PocketMon(1000, 50, 20, "피카츄");
	this->myPocketMon.setSkillSet(skill(80, "몸통 박치기"));
	this->myPocketMon.setSkillSet(skill(200, "백만볼트"));

	this->com = PocketMon(1000, 30, 50, "파이리");
	this->com.setSkillSet(skill(60, "몸통 박치기"));
	this->com.setSkillSet(skill(220, "불꽃 세례"));

	this->originalComHP = this->com.getHP();
}

void Game::print_select(){
	cout << endl << "플레이어 턴 : " << endl;
	cout << "- 0.몸통 박치기" << endl << "- 1.백만볼트 " << endl << "- 2.기본공격" << endl << "- 3.도망" << endl << "선택하십시오. >> ";
}

void Game::run_skill(char *user_name, char *skill_name){
	cout << user_name << "이(가) " << skill_name << "를(을) 시전했다." << endl;
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
			cout << "플레이어가 도망을 갔다." << endl;
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
				cout << this->myPocketMon.getName() << "이(가) " << this->myPocketMon.get_skillset().at(status).get_skill_name() << "를 시전하였으나, 전력이 부족했다." << endl;
				user_damage = this->myPocketMon.getDamage();
				cout << this->myPocketMon.getName() << "는(은) 기본 공격을 시전했다." << endl;
			}
		}
		else if (status == 2){
			cout << this->myPocketMon.getName() << "이(가) 기본공격을 시전했다." << endl;
			user_damage = this->myPocketMon.getDamage();
		}
		/************************************************************ ~ User Phase ********************************************************************************/

		random = rand() % 100 + 1;

		if (random <= this->com.getAvoid()) {
			tempComHP = this->com.getHP();
			cout << "하지만, " << this->com.getName() << "이(가) 피했다." << endl;
		}
		else {
			tempComHP = this->com.getDamageByUser(user_damage);
			cout << this->com.getName() << "이(가) " << user_damage << "의 데미지를 받았다!" << endl;
		}

		cout << "COM : " << "HP - " << this->com.getHP() << endl;
		if (tempComHP <= 0){
			cout << this->com.getName() << "이(가) 뻗었다!!" << endl;
			print_victory();
			break;
		}
		/************************************************************ ~ User Result Phase ************************************************************************/

		cout << endl << "컴퓨터의 턴이 왔다." << endl;
		float current_com_HP = (float)tempComHP / originalComHP;

		if (current_com_HP < 0.1){
			int avoidField = rand() % 2;
			if (avoidField == 1){
				cout << "하지만, " << this->com.getName() << "이(가) 도망쳤다." << endl;
				print_victory();
				break;
			}
		}

		random = rand() % 100 + 1;

		if (current_com_HP <= 0.5){
			com_skill_set = rand() % 2;
			cout << this->com.getName() << "이(가) 반격을 하였다." << endl;

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
				cout << this->com.getName() << "의 일반공격!" << endl;
				com_damage = this->com.getDamage();
			}
			else if (com_skill_set == 0) {
				run_skill(this->com.getName(), this->com.get_skillset().at(com_skill_set).get_skill_name());
				com_damage = this->com.get_skillset().at(com_skill_set).get_damage();
			}
		}
		if (random <= this->myPocketMon.getAvoid())
			cout << this->myPocketMon.getName() << "이(가) 공격을 피했다." << endl;
		else {
			this->myPocketMon.getDamageByUser(com_damage);
			cout << this->myPocketMon.getName() << "이(가) " << com_damage << "의 데미지를 입었다." << endl;
		}

		cout << "USER: " << "HP - " << this->myPocketMon.getHP() << endl;

		/************************************************************* ~ Computer Phase ******************************************************************/

		if (this->myPocketMon.getHP() <= 0){
			cout << this->myPocketMon.getName() << "이(가) 뻗었다!!" << endl << endl;
			print_game_over();
			break;
		}

		cout << "**************************" << endl;
		/************************************************************* ~ Computer Result Phase **********************************************************/
	}
}
