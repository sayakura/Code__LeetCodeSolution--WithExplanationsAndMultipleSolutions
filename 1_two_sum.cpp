// Original O(N^2) Solution 
// Loop through the array, check if current element at index i with all elements at index [i + 1,  array.length) equals to target, 
// if yes, save both index to an array and return it.
// C Version appr 150 ms, very slow
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int *res = (int *)malloc(sizeof(int) * 2);
    while (i < numsSize)
    {
        j = i + 1;
        while(j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j; 
                return (res);
            }
            j++;
        }
        i++;
    }
    return (NULL);
}

// C++ Version 154ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1; 
            for (; j < nums.size(); j++) // check [i + 1 .. nums.size)
            {
                if (nums[i] + nums[j] == target) // if we found the pair, i and j
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return (ret);
                }
            }
        }
        return (ret);
    }
};

// Original O(N) Solution 1 16ms ~ 8ms(with speed up trick)
// Map every value from array nums as a key and  with its indexes as value, since there might be duplicated value in the array(duplicated key for the map), I used a vector for the value.
// i.e. [0, 3, 2, 0], all the pairs for the map would be (0, {0, 3}), (3, {1}), (2, {2}),
// then I will loop through the array again, subtracting target with each element, and lookup the difference from the map, if I found it, let's say the difference is 0 in thicase, I will have to loop throught its value(the vector) again and make sure I return different indexes(0 and 3), not (0, 0).
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> map1;
        vector<int> ret;
        int temp;
    
        for (int i = 0; i < nums.size(); i++)  
            map1[nums[i]].push_back(i); // generate the map
        
        for (int i = 0; i < nums.size(); i++) // loop through the array again
		{
            temp = target - nums[i]; // calculate the difference. 
            if (map1[temp].size() > 0) // if our map contains the difference
			{ // by entering the loop, it means that we have found the first part of the pair
                for (int j = 0; j < map1[temp].size(); j++) // loop through the vector to find the second part of the pair
				{
                    if (i != map1[temp][j]) // we don't want the values of the pair are identical, in the example of ( 0, {0, 3} ), this will skip the first index 0. 
					{
                        ret.push_back(i);
                        ret.push_back(map1[temp][j]);
                        return (ret);
                    }
                }
            }
        }
        return ret;
    }
};

// O(N) Solution 4ms 
// same as the solution above but since we are only looking for if any of the two numbers add up to the target we don't really need a vector for only two number
// in this case, I save the first occurrence of the difference in the map, and whenever I find the second one, I just return it along with the first one
// and this enables me to only loop through the map once. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> hm;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i];
            if (hm.find(difference) != hm.end()){
                ret.push_back(hm[difference]);
                ret.push_back(i);
                return ret;
            }            
            hm[nums[i]] = i;
        }
        return (ret);
    }
};

