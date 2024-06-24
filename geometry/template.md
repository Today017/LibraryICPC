[top](../README.md)

# [幾何テンプレート](./template.hpp)

## Inequality

`bool almostEqual(long double a, long double b)` 

`bool lessThan(long double a, long double b)`

`bool greaterThan(long double a, long double b)`

`bool lessThanOrEqual(long double a, long double b)`

`bool greaterThanOrEqual(long double a, long double b)`
- EPSを用いた不等式評価

## Structure

`Point(long double x, long double y)`
- 二次元平面状の位置ベクトル $(x, y)$

---

`Segment(Point a, Point b)`

`Segment(long double A, long double B, long double C)`
- 線分

---

`Line(Point a, Point b)`

`Line(long double A, long double B, long double C)`
- 直線

(一般には==が壊れるので注意)

---

`Circle(long double x, long double y, long double r)`

`Circle(Point _center, long double r)`
- 円

## Point and Vector

`Orientation ccw(Point p0, Point p1, Point p2)`
- 点の進行方向

```cpp
enum Orientation {
    COUNTER_CLOCKWISE,
    CLOCKWISE,
    ONLINE_BACK,
    ONLINE_FRONT,
    ON_SEGMENT
};
```

--- 

`Point projection(Point p1, Point p2, Point p)`

`Point projection(Line l, Point p)`
- 射影

---

`Point reflection(Point p1, Point p2, Point p)`

`Point reflection(Line l, Point p)`
- 反射

## Segment and Line

`bool isParallel(Line(Segment) l1, Line(Segment) l2)`
- 平行判定

`bool isParallel(Line(Segment) l1, Line(Segment) l2)`
- 垂直判定

---

`bool isPointOnLine(Point p, Line l)`
- 直線上に点が存在するか判定


`bool isPointOnSegment(Point p, Line l)`
- 線分上に点が存在するか判定

`bool isIntersecting(Segment s1, Segment s2)`
- 線分の交差判定

`Point getIntersection(Segment s1, Segment s2)`
- 二つの線分の交点を返す

--- 

`long double distancePointToSegment(Point p, Segment s)`
- 点と線分の距離

`long double distanceSegmentToSegment(Segment s1, Segment s2)`
- 線分と線分の距離

## Polygon

`long double getPolygonArea(vector<Point> points)`
- 多角形の面積を求める

---

`bool isConvex(vector<Point> points)`
- 凸多角形かどうかの判定

---

`bool isPointOnPolygon(vector<Point> polygon, Point p)`
- 点が凸多角形の辺上に存在するか判定

`bool isPointInsidePolygon(vector<Point> polygon, Point p)`
- 点が凸多角形の内部に存在するか判定(たまに↑を包含するっぽい)

## Convex Polygon

`vector<Point> convexHull(vector<Point> points, bool include_collinear = false)`
- 凸包

---
`long double convexHullDiameter(vector<Point> hull)`
- 凸包の直径

---
`vector<Point> cutPolygon(vector<Point> g, Point p1, Point p2)`
- 凸包をカットして左側を返す

## Point Set

`long double closestPair(vector<Point> points, int l, int r)`
- 最近点対
（x座標の値でソートされた点列を渡す）

## Segment Set

`int countIntersections(vector<Segment> segments)`
- 線分集合の交点の個数を返す

## Circle

`int countCirclesIntersection(Circle c1, Circle c2)`
- 二つの円の交点の個数

---

`Circle getInCircle(Point A, Point B, Point C)`
- 内接円の取得 

---

`Circle getCircumCircle(Point A, Point B, Point C)`
- 外接円の取得

---

`vector<Point> getCircleLineIntersection(Circle c, Point p1, Point p2)`
- 円と直線の交点の取得

`vector<Point> getCirclesIntersect(Circle c1, Circle c2)`
- 二つの円の交点の取得

`vector<Point> getTangentLinesFromPoint(Circle c, Point p)`
- 点$p$を通る接線との交点を取得

`vector<Segment> getCommonTangentsLine(Circle c1, Circle c2)`
- 二つの円の共通接線を取得