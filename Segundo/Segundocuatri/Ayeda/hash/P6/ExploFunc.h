#ifndef EXPLORATIONFUNCTION
#define EXPLORATIONFUNCTION
template<class Key>
class ExplorationFunction {
  public:
    unsigned operator()(const Key& k, unsigned i) const = 0;
};
template<class Key>
class efLineal: public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& k, unsigned i) const {
      return i;
    }
};
#endif