#ifndef MAP_H
#define MAP_H
class map {
 public:
  map(int N);
  ~map();
  void showMap();
  void findRoute1();
  void findRoute2();
  void findRoute3();
  void showRoute();
 private:
  int n;
  int distance;
  int** height{};
  int** route{};


};


#endif
