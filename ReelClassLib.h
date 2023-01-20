#pragma once
class Quewe
{
public:
	Quewe();
	Quewe(int);
	bool Empty();
	bool Full();
	void AddElem(int);
	void ShowReel() noexcept;
	int Extract();
	int RandExtract(int&);
	void ClearReel() { reelLenCurr = 0; }
	size_t GetCurrLen() { return reelLenCurr; }
	~Quewe();

private:
	int* reel;
	size_t reelLenMax;
	size_t reelLenCurr;
};
