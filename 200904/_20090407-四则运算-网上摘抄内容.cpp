#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;

enum types { DELIMITER = 1, VARIABLE, NUMBER};

class parser {
   char *exp_ptr;   // points to the expression
   char token[80]; // holds current token
   char tok_type;   // holds token's type

   void eval_exp2(double &result);
   void eval_exp3(double &result);
   void eval_exp4(double &result);
   void eval_exp5(double &result);
   void eval_exp6(double &result);
   void atom(double &result);
   void get_token();
   void serror(int error);
   int isdelim(char c);
public:
   parser();
   double eval_exp(char *exp);
};

// parser constructor
parser::parser()
{
   exp_ptr = NULL;
}

// Parser entry point.
double parser::eval_exp(char *exp)
{
   double result;

   exp_ptr = exp;

   get_token();
   if(!*token) {
     serror(2); // no expression present
     return 0.0;
   }
   eval_exp2(result);
   if(*token) serror(0); // last token must be null
   return result;
}

// Add or subtract two terms.
void parser::eval_exp2(double &result)
{
   register char op;
   double temp;

   eval_exp3(result);
   while((op = *token) == '+' || op == '-') {
     get_token();
     eval_exp3(temp);
     switch(op) {
       case '-':
         result = result - temp;
         break;
       case '+':
         result = result + temp;
         break;
     }
   }
}

// Multiply or divide two factors.
void parser::eval_exp3(double &result)
{
   register char op;
   double temp;

   eval_exp4(result);
   while((op = *token) == '*' || op == '/' || op == '%') {
     get_token();
     eval_exp4(temp);
     switch(op) {
       case '*':
         result = result * temp;
         break;
       case '/':
         result = result / temp;
         break;
       case '%':
         result = (int) result % (int) temp;
         break;
     }
   }
}

// Process an exponent
void parser::eval_exp4(double &result)
{
   double temp, ex;
   register int t;

   eval_exp5(result);
   if(*token== '^') {
     get_token();
     eval_exp4(temp);
     ex = result;
     if(temp==0.0) {
       result = 1.0;
       return;
     }
     for(t=(int)temp-1; t>0; --t) result = result * (double)ex;
   }
}

// Evaluate a unary + or -.
void parser::eval_exp5(double &result)
{
   register char   op;

   op = 0;
   if((tok_type == DELIMITER) && *token=='+' || *token == '-') {
     op = *token;
     get_token();
   }
   eval_exp6(result);
   if(op=='-') result = -result;
}

// Process a parenthesized expression.
void parser::eval_exp6(double &result)
{
   if((*token == '(')) {
     get_token();
     eval_exp2(result);
     if(*token != ')')
       serror(1);
     get_token();
   }
   else atom(result);
}

// Get the value of a number.
void parser::atom(double &result)
{
   switch(tok_type) {
     case NUMBER:
       result = atof(token);
       get_token();
       return;
     default:
       serror(0);
   }
}

// Display a syntax error.
void parser::serror(int error)
{
   static char *e[]= {
       "Syntax Error",
       "Unbalanced Parentheses",
       "No expression Present"
   };
   cout << e[error] << endl;
}

// Obtain the next token.
void parser::get_token()
{
   register char *temp;

   tok_type = 0;
   temp = token;
   *temp = '\0';

   if(!*exp_ptr) return; // at end of expression

   while(isspace(*exp_ptr)) ++exp_ptr; // skip over white space

   if(strchr("+-*/%^=()", *exp_ptr)){
     tok_type = DELIMITER;
     // advance to next char
     *temp++ = *exp_ptr++;
   }
   else if(isalpha(*exp_ptr)) {
     while(!isdelim(*exp_ptr)) *temp++ = *exp_ptr++;
     tok_type = VARIABLE;
   }
   else if(isdigit(*exp_ptr)) {
     while(!isdelim(*exp_ptr)) *temp++ = *exp_ptr++;
     tok_type = NUMBER;
   }

   *temp = '\0';
}

// Return true if c is a delimiter.
int parser::isdelim(char c)
{
   if(strchr(" +-/*%^=()", c) || c==9 || c=='\r' || c==0)
     return 1;
   return 0;
}

int main()
{
   char expstr[80];

   cout << "Enter a period to stop.\n";

   parser ob; // instantiate a parser

   for(;;) {
     cout << "Enter expression: ";
     cin.getline(expstr, 79);
     if(*expstr=='.') break;
     cout << "Answer is: " << ob.eval_exp(expstr) << "\n\n";
   };

   return 0;
}