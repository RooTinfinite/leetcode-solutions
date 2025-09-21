class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:

        d = [0]*len(student_id)

        pSet,nSet = set(positive_feedback), set(negative_feedback)

        for i,s in enumerate(report):
            for w in s.split(): d[i]+= 3*(w in pSet)-(w in nSet)

        return [id for _i, id in 
                nsmallest(k, enumerate(student_id), 
                key = lambda x: (-d[x[0]],x[1]))]