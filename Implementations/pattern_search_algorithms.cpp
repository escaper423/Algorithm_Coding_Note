#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
#pragma warning(disable:4996)
using namespace std;

int* MakeLPSTable(const string pat)
{
	int* lps_array = (int *)malloc(sizeof(int) * pat.length());
	int lpslen = 0;
	lps_array[0] = 0;
	int i = 1;
	while (i < pat.size())
	{
		if (pat[i] == pat[lpslen])
		{
			lpslen++;
			lps_array[i] = lpslen;
			i++;
		}
		else
		{
			if (lpslen != 0)
				lpslen = lps_array[lpslen - 1];
			else
			{
				lps_array[i] = 0;
				i++;
			}
		}
	}
	return lps_array;
}

int * make_zarray(const string p)
{
	int *z = (int *)malloc(sizeof(int) * p.length());
	z[0] = 0;
	int l = 0,r = 0;
	for (int i = 1; i < p.length(); i++)
	{
		if (i > r)
		{
			l = r = i;
			while (r < p.length() && p[r - l] == p[r])
				r++;
			
			z[i] = r - l;
			r--;
		}
		else
		{
			int k = i - l;
			if (z[k] < r - i + 1)
				z[i] = z[k];
			else
			{
				l = i;

				while (r < p.length() && p[r - l] == p[r])
					r++;
	
				z[i] = r - l;
				r--;
			}
		}
	}
	return z;
}
void z_search(const string txt, const string pat)
{
	string newstr(pat + '$' + txt);
	int *z = make_zarray(newstr);
	for (int i = 0; i < newstr.size(); i++)
	{
		if (z[i] == pat.length())
			cout << "Found a pattern starts with " << i << "th index." << endl;
	}
	delete z;
}
void kmp_search(const string txt, const string pat)
{
	
	int *lps = MakeLPSTable(pat);
	int i = 0,j = 0;
	while (i < txt.length())
	{
		//matched
		if (txt[i] == pat[j])
		{
			i++;
			j++;
			if (j == pat.length())
			{
				cout << "Found a pattern starts with " << i-j << "th index." << endl;
				j = lps[j - 1];
			}
		}
		else
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
	delete lps;
}
void rabin_karp(const string txt, const string pat)
{
	int d = 256;
	int h = 1;
	int q = 109;
	int m = pat.length();
	int n = txt.length();

	int p = 0, t = 0;

	for (int i = 0; i < m - 1; i++)
		h = (d*h) % q;

	for (int i = 0; i < m; i++)
	{
		p = (d*p + pat[i]) % q;
		t = (d*t + txt[i]) % q;
	}

	int j;
	for (int i = 0; i <= n - m; i++)
	{
		if (p == t)
		{
			for (j = 0; j < m; j++)
			{
				if (txt[i + j] != pat[j])
					break;
			}
			if (j == m)
				cout << "Found a pattern starts with " << i << "th index." << endl;
		}

		if (i < n - m)
		{
			t = (d*(t - txt[i] * h) + txt[i + m]) % q;
			if (t < 0)
				t = (t + q);
		}
	}
}

int main()
{

	string txt("asddsgojspgjpasogjaspoadaasdjapofjadaopsdjaopdajfajdgpamspjdpokdapodksaodkopagjdasfasgkfopadsgjdapsgjasdp[fjasp[fjasdopfgasdofaspdfkaspofdjaspfjasp[dfjadop[fjasdpgjaspifjopdjaopdkapodasdasdpoakdasdadadasdkopakdpoasdpoajdasdaopsda[asdigjsapdjopkadpsdkapodkaspd[jip[osjgp[iasojgp[");
	string pat("asd");
	auto s = chrono::steady_clock::now();
	cout << "rabin karp searching...\n";
	rabin_karp(txt, pat);
	cout << "rabin karp ended : ";
	double elapsed = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - s).count();
	cout << setprecision(4) << fixed << elapsed / 1e9  << "s" << endl;
	
	s = chrono::steady_clock::now();
	cout << "kmp searching...\n";
	kmp_search(txt, pat);
	cout << "kmp ended : ";
	elapsed = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - s).count();
	cout << setprecision(4) << fixed << elapsed / 1e9 << "s" << endl;

	s = chrono::steady_clock::now();
	cout << "z searching..." << endl;
	z_search(txt, pat);
	cout << "z ended : ";
	elapsed = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - s).count();
	cout << setprecision(4) << fixed << elapsed / 1e9 << "s" << endl;

	return 0;
}
