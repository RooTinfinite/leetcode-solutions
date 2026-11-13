class Solution:
    def repeatedStringMatch(self, a: str, b: str, x: int, y: int) -> bool:
        orig_a, orig_b = a, b
        orig_x, orig_y = x, y
        A_LEN, B_LEN = len(a), len(b)
        if B_LEN * y > A_LEN * x:
            return False
        if x == 1:
            while y > 1:
                b += b
                y -= 1
            return True if b in a else False
        a += a
        x -= 1
        while len(a) <= len(b) and x > 1:
            a += a
            x -= 1
        found_at = -1
        print(a, b)
        for i in range(len(a)):
            new_a = a[i:] + a[:i]
            not_completed = False
            found = 0
            for j in range(len(b)-1, len(new_a), len(b)):
                if new_a[j-(len(b)-1):j+1] == b:
                    found += 1
                else:
                    not_completed=True
                    break
            if not not_completed or found >= y:
                print(i)
                found_at = i
                break
        if found_at == -1:
            return False
        missed = found_at
        print('actual', (len(a)+(len(orig_a)*(x))) - missed, len(a))
        if (len(a)+(len(orig_a)*(x-1))) - missed < len(orig_b)*orig_y:
            return False
        return True