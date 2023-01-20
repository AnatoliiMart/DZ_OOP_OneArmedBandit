#pragma once
Quewe* reel1 = new Quewe(9);
Quewe* reel2 = new Quewe(9);
Quewe* reel3 = new Quewe(9);

const int creditBegin        = 100;
const int lessCredits        = 5;
const int creditsToWin       = 10;
const int creditsForWinStuck = 15;
const int jackpotCredits     = 1000;
int res1   = 0;
int res2   = 0;
int res3   = 0;
int choose = 0;
int creditCurr = creditBegin;