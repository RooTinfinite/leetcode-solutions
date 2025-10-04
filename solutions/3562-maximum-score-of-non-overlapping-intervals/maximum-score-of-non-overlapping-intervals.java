class Solution {
    public int[] maximumWeight(List<List<Integer>> intervals) {
    int n = intervals.size();
    List<Interval> sortedIntervals = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      sortedIntervals.add(new Interval(intervals.get(i).get(0), intervals.get(i).get(1), intervals.get(i).get(2), i));
    }
    sortedIntervals.sort(Comparator.comparingInt(Interval::getEnd).thenComparingInt(Interval::getStart));

    List<List<BestOption>> best = new ArrayList<>(5);
    for (int i = 0; i < 5; i++) {
      best.add(new ArrayList<>());
    }
    best.get(0).add(new BestOption(0, 0, new ArrayList<>()));

    for (Interval interval : sortedIntervals) {
      for (int k = 4; k >= 1; k--) {
        if (k == 1) {
          BestOption candidate = new BestOption(interval.end, interval.weight, new ArrayList<>());
          candidate.indices.add(interval.index);
          if (best.get(k).isEmpty() || candidate.weight > best.get(k).get(best.get(k).size() - 1).weight ||
              (candidate.weight == best.get(k).get(best.get(k).size() - 1).weight && compareIndices(candidate.indices, best.get(k).get(best.get(k).size() - 1).indices) < 0)) {
            best.get(k).add(candidate);
          }
        } else {
          if (best.get(k - 1).isEmpty()) {
            continue;
          }
          int s = interval.start;
          int l = 0, r = best.get(k - 1).size() - 1, pos = -1;
          while (l <= r) {
            int m = l + (r - l) / 2;
            if (best.get(k - 1).get(m).end < s) {
              pos = m;
              l = m + 1;
            } else {
              r = m - 1;
            }
          }
          if (pos != -1) {
            BestOption previous = best.get(k - 1).get(pos);
            BestOption candidate = new BestOption(interval.end, previous.weight + interval.weight, new ArrayList<>(previous.indices));
            candidate.indices.add(interval.index);
            Collections.sort(candidate.indices);
            if (best.get(k).isEmpty() || candidate.weight > best.get(k).get(best.get(k).size() - 1).weight ||
                (candidate.weight == best.get(k).get(best.get(k).size() - 1).weight && compareIndices(candidate.indices, best.get(k).get(best.get(k).size() - 1).indices) < 0)) {
              best.get(k).add(candidate);
            }
          }
        }
      }
    }

    long maxWeight = -1;
    List<Integer> result = new ArrayList<>();
    for (int k = 1; k <= 4; k++) {
      if (!best.get(k).isEmpty()) {
        BestOption current = best.get(k).get(best.get(k).size() - 1);
        if (current.weight > maxWeight || (current.weight == maxWeight && compareIndices(current.indices, result) < 0)) {
          maxWeight = current.weight;
          result = new ArrayList<>(current.indices);
        }
      }
    }

    int[] intArray = result.stream()
                .mapToInt(Integer::intValue) // Convert Stream<Integer> to IntStream
                .toArray(); 
    return intArray;
  }

  private int compareIndices(List<Integer> indices1, List<Integer> indices2) {
    for (int i = 0; i < Math.min(indices1.size(), indices2.size()); i++) {
      if (indices1.get(i) != indices2.get(i)) {
        return Integer.compare(indices1.get(i), indices2.get(i));
      }
    }
    return Integer.compare(indices1.size(), indices2.size());
  }

  static class Interval {
    public Integer start;
    public Integer end;
    public Integer weight;
    public Integer index;

    public Interval(Integer start, Integer end, Integer weight, Integer index) {
      this.start = start;
      this.end = end;
      this.weight = weight;
      this.index = index;
    }

    public Integer getStart() {
      return start;
    }

    public void setStart(Integer start) {
      this.start = start;
    }

    public Integer getEnd() {
      return end;
    }

    public void setEnd(Integer end) {
      this.end = end;
    }

    public Integer getWeight() {
      return weight;
    }

    public void setWeight(Integer weight) {
      this.weight = weight;
    }

    public Integer getIndex() {
      return index;
    }

    public void setIndex(Integer index) {
      this.index = index;
    }
  }

  static class BestOption {
    public int end;
    public long weight;
    public List<Integer> indices;

    public BestOption(int end, long weight, List<Integer> indices) {
      this.end = end;
      this.weight = weight;
      this.indices = indices;
    }
  }
}