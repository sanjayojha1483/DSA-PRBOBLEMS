class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;   // yaha output likhenge
        int i = 0;       // yeh read pointer hai

        while (i < chars.size()) {
            char current = chars[i];  // current character
            int count = 0;

            // Same letters count karo
            while (i < chars.size() && chars[i] == current) {
                count++;
                i++;
            }

            // Character output me likho
            chars[write] = current;
            write++;

            // Agar count > 1 to uski digits likho
            if (count > 1) {
                string num = to_string(count);
                for (int j = 0; j < num.size(); j++) {
                    chars[write] = num[j];
                    write++;
                }
            }
        }

        return write;  // final compressed length
    }
};
