//next balanced sequence

bool nbs(string & s) {
    int n = s.size();
    int d = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(')
            d--;
        else
            d++;

        if (s[i] == '(' && d > 0) {
            d--;
            int a = (n - i - 1 - d) / 2;
            int b = n - i - 1 - a;
            string next = s.substr(0, i) + ')' + string(a, '(') + string(b, ')');
            s.swap(next);
            return true;
        }
    }
    return false;
}