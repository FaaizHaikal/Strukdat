#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;

typedef struct {
  int x, y, r;

  bool operator<(const Circle& other) const {
        return r > other.r;
  }
} Circle;

double halfCircumferenceOfCircle(int r){
  return PI * r;
}

double distance2PointsSquared(int x1, int y1, int x2, int y2){
  return (pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double outerTangentLineLength(int r1, int r2, int d){
  return sqrt(d - pow(r1 - r2, 2));
}
int main(){
  int n;
  while(true){
    std::cin >> n;
    if(n == -1)
      break;
    std::priority_queue<Circle> pq;
    while(n--){
      Circle c;
      std::cin >> c.x >> c.y >> c.r;
      pq.push(c);
    }
    double ans = 0;
    while(pq.size() > 1){
      Circle c1 = pq.top();
      pq.pop();
      Circle c2 = pq.top();
      pq.pop();
      double d = distance2PointsSquared(c1.x, c1.y, c2.x, c2.y);
      if(d <= pow(c1.r - c2.r, 2)){
        pq.push(c1);
        continue;
      }
      double l = outerTangentLineLength(c1.r, c2.r, d);
      ans += l;
      c1.r = l;
      pq.push(c1);
    }
    std::cout << std::fixed << std::setprecision(2) << ans + pq.top().r << "\n";
  }
}