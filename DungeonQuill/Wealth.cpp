#include "Wealth.h"

std::string Wealth::coinNameCH[] = { "","铜币" ,"银币" ,"银金币" ,"金币" ,"铂金币" };
std::string Wealth::coinNameEN[] = { "","cp" ,"sp" ,"ep" ,"gp" ,"pp" };
int Wealth::coinWeight[] = { 0,1,10,50,100,1000 };

Wealth::Wealth(int cp, int sp, int ep, int gp, int pp) {
	copperCoin = cp;
	silverCoin = sp;
	electrumCoin = ep;
	goldCoin = gp;
	platinumCoin = pp;
}

int* Wealth::getWealth() {
	static int wealth[5] = { copperCoin, silverCoin, electrumCoin, goldCoin, platinumCoin };

	return wealth;
}