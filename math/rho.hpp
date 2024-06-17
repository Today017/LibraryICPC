#include "../../kyopro_library/template.hpp"

vector<ll> factors(ll x){
    vector<ll> fs;
    FILE* fp = popen(("factor " + to_string(x)).c_str(), "r");
    char buf[1024];
    fgets(buf, 1024, fp);
    pclose(fp);
    string s = buf;
    s = s.substr(s.find(":") + 1);
    stringstream ss(s);
    ll f;
    while(ss >> f){
        fs.push_back(f);
    }
    return fs;
}
