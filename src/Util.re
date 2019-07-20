let rec remove_at = (n, list) =>
  switch (list) {
  | [] => []
  | [h, ...t] =>
    if (n == 0) {
      t;
    } else {
      [h, ...remove_at(n - 1, t)];
    }
  };