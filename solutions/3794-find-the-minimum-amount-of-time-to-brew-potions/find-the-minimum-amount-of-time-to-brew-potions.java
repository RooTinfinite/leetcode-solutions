class Solution {
    boolean isValid(int[] skill, int[] mana, long[] prevPotionEndTimes, int currPotionIdx, long startTime)
    {
        long endTime = startTime;
        for (int i = 0; i < skill.length; i++)
        {
            if (endTime < prevPotionEndTimes[i])
                return false;
            endTime += ((long)skill[i] * mana[currPotionIdx]);
        }
        return true;
    }
    long getStartTime(int[] skill, int[] mana, int currPotionIdx, long lowTime, long[] prevPotionEndTimes)
    {
        int wizardCount = skill.length;
        long highTime = prevPotionEndTimes[wizardCount - 1];
        long ans = highTime;
        //============================================================================================
        while(lowTime <= highTime)
        {
            long midTime = lowTime + (highTime - lowTime) / 2;
            if (isValid(skill, mana, prevPotionEndTimes, currPotionIdx, midTime))
            {
                ans = midTime;
                highTime = midTime - 1;
            }
            else
                lowTime = midTime + 1;
        }
        //============================================================================================
        return ans;
    }
    public long minTime(int[] skill, int[] mana) 
    {
        int wizardCount = skill.length, potionCount = mana.length;
        long prevStartTime = 0; //startTime of brewing "previous" Potion
        
        //potionEndTimes[i] denotes end time at which ith wizard finishes brewing "current" Potion
        long[] potionEndTimes = new long[wizardCount]; 
        //===================================================================================================
        for (int i = 0; i < potionCount; i++)
        {
            long startTime = (i == 0)? 0 : getStartTime(skill, mana, i, prevStartTime + 1, potionEndTimes);
            
            long endTime = startTime;
            for (int j = 0; j < wizardCount; j++)
            {
                endTime += ((long)(skill[j]) * (mana[i]));
                potionEndTimes[j] = endTime;
            }
            
            prevStartTime = startTime;
        }
        //======================================================================================================
        return potionEndTimes[wizardCount - 1];
        
    }
}