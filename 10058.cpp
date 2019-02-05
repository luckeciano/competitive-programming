#include <iostream>
#include <sstream>
using namespace std;
bool err;

void verb(stringstream &s) {
    //cout << "verb" << endl;
    string word;
    s >> word;
    if (word == "hate" || word == "hates" || word == "love" || word == "loves" || word == "know"
        || word == "knows" || word == "like" || word == "likes") {
           // cout << word << endl;
            //s.get();
            return;
    } else {
        err = true;
    }


}

void actor(stringstream &s) {
    //cout << "actor" << endl;
    string word;
    s >> word;
    if (word == "a" || word == "the") {
       // s.get();
        actor(s);
    } else if (word == "tom" || word == "jerry" || word == "goofy" || word == "mickey" ||
               word == "jimmy" || word == "dog" || word == "cat" || word == "mouse") {
               // cout << word << endl;
                //s.get();
                return;
    } else {
        err = true;
    }

}

void active_list (stringstream &s) {
    //cout << "active list" << endl;
    string word;
    actor(s);
    streampos p_orig = s.tellg();
    s >> word;
    if (word == "and") {
        //s.get();
        active_list(s);
    } else {
        s.seekg(p_orig);

    }
}

void action (stringstream &s) {
//cout << "action" << endl;
    active_list(s);
    verb(s);
    active_list(s);
}


void statement (stringstream &s) {
    //cout << "statement" << endl;
    action(s);
    string word;
    streampos p_orig = s.tellg();
    if (s >> word, word == ",") {
        //s.get(); s.get();
        statement(s);
    } else {
        s.seekg(p_orig);
    }



}


int main () {
    string state;
    while (getline (cin, state)) {
        stringstream ss(state);
        err = false;
        string k;
        statement(ss);
        ss >> k;
        bool read = false;
        if (k.size() != 0) read = true;
        if (read) err = true;
        //cout << err << endl;
        if (!err) cout << "YES I WILL" << endl;
        else cout << "NO I WON'T" << endl;
    }

}
