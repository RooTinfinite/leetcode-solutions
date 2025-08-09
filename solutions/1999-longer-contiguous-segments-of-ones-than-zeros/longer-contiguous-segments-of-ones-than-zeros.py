from collections import defaultdict

class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        len_s = len(s)
        
        max_len_contiguous_segement_of_ones = 0
        running_len_contiguous_segment_of_ones = 0
        prev_b = None
        i = 0
        while (i < len_s):
            b = s[i]
            if (prev_b is not None and prev_b == b == '1'):
                running_len_contiguous_segment_of_ones += 1
                max_len_contiguous_segement_of_ones = max(max_len_contiguous_segement_of_ones, running_len_contiguous_segment_of_ones)
            elif ((prev_b is None or prev_b is '0') and b == '1'):
                running_len_contiguous_segment_of_ones = 1
                max_len_contiguous_segement_of_ones = max(max_len_contiguous_segement_of_ones, running_len_contiguous_segment_of_ones)
            else:
                running_len_contiguous_segment_of_ones = 0

            prev_b = b
            i += 1

        max_len_contiguous_segement_of_zeros = 0
        running_len_contiguous_segment_of_zeros = 0
        prev_b = None
        i = 0
        while (i < len_s):
            b = s[i]
            if (prev_b is not None and prev_b == b == '0'):
                running_len_contiguous_segment_of_zeros += 1
                max_len_contiguous_segement_of_zeros = max(max_len_contiguous_segement_of_zeros, running_len_contiguous_segment_of_zeros)
            elif ((prev_b is None or prev_b is '1') and b == '0'):
                running_len_contiguous_segment_of_zeros = 1
                max_len_contiguous_segement_of_zeros = max(max_len_contiguous_segement_of_zeros, running_len_contiguous_segment_of_zeros)
            else:
                running_len_contiguous_segment_of_zeros = 0

            prev_b = b
            i += 1

        return max_len_contiguous_segement_of_ones > max_len_contiguous_segement_of_zeros