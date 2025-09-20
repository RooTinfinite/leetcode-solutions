class Solution:
    def minNumberOfHours(self, initial_energy, initial_experience, opponent_energies, opponent_experiences):
        last_opponent_energy = opponent_energies[-1]
        ret_val = last_opponent_energy + 1
        last_opponent_energy_index = len(opponent_energies) - 1
        i = last_opponent_energy_index - 1
        while (i >= 0):
            ret_val += opponent_energies[i]
            i -= 1
        ret_val -= initial_energy
        if (ret_val < 0):
            ret_val = 0
        
        curr_experience = initial_experience
        for i, opponent_experience in enumerate(opponent_experiences):
            if opponent_experience>=curr_experience:
                ret_val+=opponent_experience - curr_experience + 1
                curr_experience += opponent_experience - curr_experience + 1
            curr_experience += opponent_experience

        return ret_val