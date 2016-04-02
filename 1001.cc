#include <iostream>
#include <string>

using namespace std;

typedef struct BigNum {
public:
	string frac;			
	unsigned long exp;		
}BigNum;

static BigNum zero;
static BigNum one;

BigNum process(string s) 
{
	bool isZero = true;
	BigNum bignum;

	bignum.frac = string(s.length(), '0');
	bignum.exp = 0;

	int i, j;
	i = j = s.length()-1;
	while (i >= 0)
	{
		if (s[i] != '0')
			isZero = false;
		if (s[i] == '.') 	
			bignum.exp = s.length()-i-1;
		else
			bignum.frac[j--] = s[i];
		i--;
	}
	if (isZero)
		bignum.exp = 0;
	return bignum;
}

BigNum multi(BigNum x, BigNum y)
{
	BigNum res;
	string a = x.frac;
	string b = y.frac;
	string ans(a.length()+b.length(), '0');
    int carry = 0;
	for (int i = a.size() - 1; i >= 0 ; i--)  
    {    
        int an = a[i] - '0';  
        for (int j = b.size() - 1; j >= 0 ; j--)  
        {  
            int bn = b[j] - '0';  
            int sum = an * bn + carry + ans[i+j+1] - '0';  
            carry = sum / 10;  
            ans[i+j+1] = sum % 10 + '0';  
        }  
        if (carry) ans[i] += carry;  
    }
	res.frac = ans;
	res.exp = x.exp+y.exp;
	return res;
}

BigNum pow(BigNum x, int n)
{
	if (x.frac.empty() || "0" == x.frac) 
		return zero;
    if (0 == n) 
		return one;
    if (1 == n) 
		return x;
	
    BigNum divideStr = pow(x, n/2);
    divideStr = multi(divideStr, divideStr);  
    if (n % 2) 
		divideStr = multi(divideStr, x);
    return divideStr;
}

void printNum(BigNum x)
{
	int i, pre, post;
	bool preZero, postZero;
	i = pre = post = 0;
	preZero = postZero = true;

	for (i = 0; i<x.frac.length()-x.exp; i++)
	{
		if (x.frac[i] == '0' && preZero)
			pre ++;
		else
			preZero = false;
	}
	for (i = x.frac.length()-1; i>=x.frac.length()-x.exp; i--)
	{
		if (x.frac[i] == '0' && postZero)
			post++;
		else
			postZero = false;
	}
	if (!preZero || !postZero)
	{
		for (i = pre; i<x.frac.length()-x.exp; i++)	
			cout << x.frac[i];
		if (!postZero)
			cout << '.';
		for (; i<x.frac.length()-post; i++)
			cout << x.frac[i];
	}
	else
		cout << "0";
	cout << endl;
}

int main() 
{
	zero.frac = "0";
	one.frac = "1";
	zero.exp = one.exp = 0;

	string s;
	int n;

	while(cin>>s>>n) {
		printNum(pow(process(s), n));
	}
	return 0;
}
