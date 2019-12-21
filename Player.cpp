/*
 * Player.cpp
 *
 *  Created on: May 2, 2019
 *      Author: saad
 */

#include "Player.h"


int Player::getLife() const
{
    return life;
}

void Player::setLife(int life)
{
    this->life = life;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

