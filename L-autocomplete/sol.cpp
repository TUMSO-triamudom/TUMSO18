#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
 
using namespace std;
 
char buffer[1000001];
char buffer2[1000001];
vector<string> env;
 
enum ExprEnum {
  EHole, EBase, EIf, ELet, ETwo, EFun
};
 
char base[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";
 
struct Expr;
 
struct ExprIf {
  Expr* cond;
  Expr* then;
  Expr* els;
};
 
struct ExprLet {
  string var;
  Expr* val;
  Expr* e;
};
 
struct ExprFun {
  string arg;
  Expr* body;
};
 
struct ExprTwo {
  Expr* a;
  Expr* b;
};
 
struct Expr {
  ExprEnum type;
  union {
    ExprIf* e_if;
    ExprLet* e_let;
    ExprFun* e_fun;
    ExprTwo* e_two;
  };
};
 
char* top;
 
void reload_if_needed() {
  while (true) {
    top += strspn(top, " \n");
    if (*top == 0) {
      scanf("%s", buffer);
      top = buffer;
    } else {
      break;
    }
  }
}
 
string get_id() {
  size_t n = strspn(top, "abcdefghijklmnopqrstuvwxyz_");
  strncpy(buffer2, top, n);
  buffer2[n] = 0;
  top += n;
  return buffer2;
}
 
Expr* get_expr() {
  Expr* ret = new Expr;
  reload_if_needed();
  if ((*top) == '#') {
    top++;
    ret->type = EHole;
    return ret;
  }
  if ((*top) == '(') {
    top++; reload_if_needed();
    if (strncmp(top, "LET", 3) == 0) {
      top += 3; reload_if_needed();
      string var = get_id(); reload_if_needed();
      assert(strncmp(top, "=", 1) == 0);
      top++; reload_if_needed();
      Expr* val = get_expr(); reload_if_needed();
      assert(strncmp(top, "IN", 2) == 0);
      top += 2; reload_if_needed();
      Expr* e = get_expr(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++;
 
      ret->type = ELet;
      ret->e_let = new ExprLet;
      ret->e_let->var = var;
      ret->e_let->val = val;
      ret->e_let->e = e;
      return ret;
    }
    if (strncmp(top, "PLUS", 4) == 0) {
      top += 4; reload_if_needed();
      Expr* a = get_expr(); reload_if_needed();
      Expr* b = get_expr(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++;
 
      ret->type = ETwo;
      ret->e_two = new ExprTwo;
      ret->e_two->a = a;
      ret->e_two->b = b;
      return ret;
    }
    if (strncmp(top, "MINUS", 5) == 0) {
      top += 5; reload_if_needed();
      Expr* a = get_expr(); reload_if_needed();
      Expr* b = get_expr(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++;
 
      ret->type = ETwo;
      ret->e_two = new ExprTwo;
      ret->e_two->a = a;
      ret->e_two->b = b;
      return ret;
    }
    if (strncmp(top, "IS_EQUAL", 8) == 0) {
      top += 8; reload_if_needed();
      Expr* a = get_expr(); reload_if_needed();
      Expr* b = get_expr(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++;
 
      ret->type = ETwo;
      ret->e_two = new ExprTwo;
      ret->e_two->a = a;
      ret->e_two->b = b;
      return ret;
    }
    if (strncmp(top, "CALL", 4) == 0) {
      top += 4; reload_if_needed();
      Expr* a = get_expr(); reload_if_needed();
      Expr* b = get_expr(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++;
 
      ret->type = ETwo;
      ret->e_two = new ExprTwo;
      ret->e_two->a = a;
      ret->e_two->b = b;
      return ret;
    }
    if (strncmp(top, "FUNCTION", 8) == 0) {
      top += 8; reload_if_needed();
      assert(strncmp(top, "(", 1) == 0);
      top++; reload_if_needed();
      string arg = get_id(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++; reload_if_needed();
      Expr* body = get_expr(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++;
 
      ret->type = EFun;
      ret->e_fun = new ExprFun;
      ret->e_fun->arg = arg;
      ret->e_fun->body = body;
      return ret;
    }
    if (strncmp(top, "IF", 2) == 0) {
      top += 2; reload_if_needed();
      Expr* cond = get_expr(); reload_if_needed();
      assert(strncmp(top, "THEN", 4) == 0);
      top += 4; reload_if_needed();
      Expr* then = get_expr(); reload_if_needed();
      assert(strncmp(top, "ELSE", 4) == 0);
      top += 4; reload_if_needed();
      Expr* els = get_expr(); reload_if_needed();
      assert(strncmp(top, ")", 1) == 0);
      top++;
 
      ret->type = EIf;
      ret->e_if = new ExprIf;
      ret->e_if->cond = cond;
      ret->e_if->then = then;
      ret->e_if->els = els;
      return ret;
    }
    printf(">>> %s\n", top);
    printf("impossible\n");
    exit(1);
  }
 
  top += strspn(top, base);
  ret->type = EBase;
  return ret;
}
 
void calc_vars(Expr* e) {
  switch (e->type) {
    case EHole:
      sort(env.begin(), env.end());
      env.resize(distance(env.begin(), unique(env.begin(), env.end())));
      for (auto x : env) {
        printf("%s\n", x.c_str());
      }
      exit(0);
    case EBase:
      return;
    case EIf:
      calc_vars(e->e_if->cond);
      calc_vars(e->e_if->then);
      calc_vars(e->e_if->els);
      return;
    case ELet:
      env.push_back(e->e_let->var);
      calc_vars(e->e_let->val);
      calc_vars(e->e_let->e);
      env.pop_back();
      return;
    case EFun:
      env.push_back(e->e_fun->arg);
      calc_vars(e->e_fun->body);
      env.pop_back();
      return;
    case ETwo:
      calc_vars(e->e_two->a);
      calc_vars(e->e_two->b);
      return;
  }
}
 
int main() {
  top = buffer;
  Expr* expr = get_expr();
  calc_vars(expr);
  return 0;
}
