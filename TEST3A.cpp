int main ()
{
	int w;
	int r;
	bool s;
	char i;
	double P;
	int Q;
	int Z;
	int Probel = 32; // ASCII-код пробела
	
	cout << "¬ведите целые числа P, Q, Z от 1 до 10:\n";
	cin >> P >> Q >> Z;
	s = i = 0;
	
	do {
		s += (s*i+1);
		++i;
	} while (i != P);
	cout << Probel << (Probel + 51) << "=" << setw(4) << left << s;
	
	r = i = 0;
	while (i <= Q) {
		r += i*i;
		i++;
	}
	cout << Probel << 052 << "=" << setw(4) << left << r;
	
	w = 2;
	for (i=1; i<=Z; i++)
		w = w+i*(w-1);
	cout << " W=" << setw(4) << left << w << endl;
	
	return 0;
}