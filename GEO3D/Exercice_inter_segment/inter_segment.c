#include <stdio.h>

typedef enum {false=0, true=1} bool;
typedef struct {double x; double y;} point;

bool inter_segment(point A, point B, point C, point D);
double det(point A, point B, point C);
double min(double x, double y);
double max(double x, double y);
void print_bool(bool b);

int main(int argc, char **argv)
{
  point A,B,C,D;

  // false
  A.x=0.62; A.y=1.16;
  B.x=4.54; B.y=1.16;
  C.x=5.62; C.y=3.36;
  D.x=4.84; D.y=0.24;
  print_bool(inter_segment(A,B,C,D));

  // false
  A.x=0.62; A.y=1.16;
  B.x=4.54; B.y=1.16;
  C.x=5.62; C.y=3.36;
  D.x=0.4; D.y=1.4;
  print_bool(inter_segment(A,B,C,D));

  // false
  A.x=0.62; A.y=1.16;
  B.x=0.62; B.y=3.78;
  C.x=5.62; C.y=3.36;
  D.x=0.73; D.y=2.58;
  print_bool(inter_segment(A,B,C,D));

  // true
  A.x=2.66; A.y=0.68;
  B.x=0.98; B.y=1.28;
  C.x=0.3; C.y=0.22;
  D.x=4.32; D.y=1.56;
  print_bool(inter_segment(A,B,C,D));

  // true
  A.x=0.62; A.y=1.16;
  B.x=4.54; B.y=1.16;
  C.x=5.62; C.y=3.36;
  D.x=1.56; D.y=-1.18;
  print_bool(inter_segment(A,B,C,D));

  // true
  A.x=0.62; A.y=1.16;
  B.x=0.62; B.y=3.78;
  C.x=5.62; C.y=3.36;
  D.x=0.62; D.y=1.16;
  print_bool(inter_segment(A,B,C,D));

  // true
  A.x=0.62; A.y=1.16;
  B.x=0.62; B.y=3.78;
  C.x=5.62; C.y=3.36;
  D.x=0.62; D.y=2.56;
  print_bool(inter_segment(A,B,C,D));

  return 0;
}

double det(point A, point B, point C)
{
  return A.x*B.y + B.x*C.y + C.x*A.y
       - C.x*B.y - C.y*A.x - B.x*A.y;
}

void print_bool(bool b)
{
  if(b == false)
    printf("False\n");
  else if(b == true)
    printf("True\n");
  else
    printf("Error print_bool\n");
}

double min(double x, double y)
{
  if(x<y)
    return x;
  return y;
}

double max(double x, double y)
{
  if(x>y)
    return x;
  return y;
}

bool inter_segment(point A, point B, point C, point D)
{
  double e = 0.00000000001;
  double S1 = det(A,B,C);
  double S2 = det(A,B,D);
  double S3 = det(C,D,A);
  double S4 = det(C,D,B);

  if(
    (A.x == C.x && A.y == C.y) ||
    (A.x == D.x && A.y == D.y) ||
    (B.x == C.x && B.y == C.y) ||
    (B.x == D.x && B.y == D.y))
      return true;

  // e : because of dead floating point

  if(((S1 * S2) <= e) && ((S3 * S4) <= e))
  {
    if(S1 == 0)
    {
      // TEST C sur ABC
      // Verification AB vertical
      if(A.x == B.x)
      {
        if((min(A.y,B.y) > C.y) || (C.y > max(A.y,B.y)))
          return false;
      }
      if((min(A.x,B.x) > C.x) || (C.x > max(A.x,B.x)))
        return false;
    }
    if(S2 == 0)
    {
      // TEST D sur ABD
      // Verification AB vertical
      if(A.x == B.x)
      {
        if((min(A.y,B.y) > C.y) || (C.y > max(A.y,B.y)))
          return false;
      }
      if((min(A.x,B.x) > D.x) || (D.x > max(A.x,B.x)))
        return false;
    }
    if(S3 == 0)
    {
      // TEST A sur CDA
      // Verification CD vertical
      if(C.x == D.x)
      {
        if((min(C.y,D.y) > A.y) || (A.y > max(C.y,D.y)))
          return false;
      }
      if((min(C.x,D.x) > A.x) || (A.x > max(C.x,D.x)))
        return false;
    }
    if(S4 == 0)
    {
      // TEST B sur CDB
      // Verification CD vertical
      if(C.x == D.x)
      {
        if((min(C.y,D.y) > A.y) || (A.y > max(C.y,D.y)))
          return false;
      }
      if((min(C.x,D.x) > B.x) || (B.x > max(C.x,D.x)))
        return false;
    }
    return true;
  }
  return false;
}
