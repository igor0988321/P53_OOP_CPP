#pragma once

#include <iostream>
#include"String.h"
using namespace std;


enum class VarType
{
	INT, DOUBLE, STRING
};

class var
{
	VarType type;
	int i_val;
	double d_val;
	String s_val;


    int to_int() const {
        if (type == VarType::INT) return i_val;
        if (type == VarType::DOUBLE) return (int)d_val;
        if (type == VarType::STRING) return atoi(s_val.GetCStr());
        return 0;
    }

 
    double to_double() const {
        if (type == VarType::INT) return (double)i_val;
        if (type == VarType::DOUBLE) return d_val;
        if (type == VarType::STRING) return atof(s_val.GetCStr());
        return 0.0;
    }

    
    String to_string_val() const {
        if (type == VarType::INT) {
            char buf[32];
            sprintf_s(buf, sizeof(buf), "%d", i_val);
            return String(buf);
        }
        if (type == VarType::DOUBLE) {
            char buf[32];
            sprintf_s(buf, sizeof(buf), "%f", d_val);
            return String(buf);
        }
        if (type == VarType::STRING) return s_val;
        return String("");
    }

    
    static String str_intersect(const String& s1, const String& s2) {
        char* temp = new char[s1.GetSize() + 1];
        int k = 0;
        for (int i = 0; i < s1.GetSize(); ++i) {
            char c = s1[i];
            bool found = false;
            for (int j = 0; j < s2.GetSize(); ++j) {
                if (s2[j] == c) {
                    found = true;
                    break;
                }
            }
            if (found) {
                temp[k++] = c;
            }
        }
        temp[k] = '\0';
        String res(temp);
        delete[] temp;
        return res;

    
    static String str_difference(const String& s1, const String& s2) {
        char* temp = new char[s1.GetSize() + 1];
        int k = 0;
        for (int i = 0; i < s1.GetSize(); ++i) {
            char c = s1[i];
            bool found = false;
            for (int j = 0; j < s2.GetSize(); ++j) {
                if (s2[j] == c) { found = true; break; }
            }
            if (!found) {
                temp[k++] = c;
            }
        }
        temp[k] = '\0';
        String res(temp);
        delete[] temp;
        return res;
    }

public:
    var() {
        type = VarType::INT;
        i_val = 0;
        d_val = 0.0;
        s_val = "0";
    }

    var(int val) {
        type = VarType::INT;
        i_val = val;
        d_val = (double)val;
        char buf[32];
        sprintf_s(buf, sizeof(buf), "%d", val);
        s_val = String(buf);
    }

    var(double val) {
        type = VarType::DOUBLE;
        i_val = (int)val;
        d_val = val;
        char buf[32];
        sprintf_s(buf, sizeof(buf), "%f", val);
        s_val = String(buf);
    }

    var(const char* val) {
        type = VarType::STRING;
        i_val = 0;
        d_val = 0.0;
        s_val = val ? val : "";
    }

    var(const String& val) {
        type = VarType::STRING;
        i_val = 0;
        d_val = 0.0;
        s_val = val;
    }

    void Show() const {
        if (type == VarType::INT) cout << i_val << endl;
        else if (type == VarType::DOUBLE) cout << d_val << endl;
        else if (type == VarType::STRING) cout << s_val << endl;
    }

    
    operator int() const { return to_int(); }
    operator double() const { return to_double(); }
    operator const char* () const { return s_val.GetCStr(); }
};

