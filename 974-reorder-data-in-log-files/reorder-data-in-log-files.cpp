class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](string a, string b) {
            int posA = a.find(' ');
            int posB = b.find(' ');

            string idA = a.substr(0, posA);
            string idB = b.substr(0, posB);

            string contentA = a.substr(posA + 1);
            string contentB = b.substr(posB + 1);

            bool letterA = isalpha(contentA[0]);
            bool letterB = isalpha(contentB[0]);

            if (letterA && letterB) {
                if (contentA != contentB) {
                    return contentA < contentB;
                }
                return idA < idB;
            }

            if (letterA && !letterB) {
                return true;
            }

            if (!letterA && letterB) {
                return false;
            }

            return false;
        });

        return logs;
    }
};