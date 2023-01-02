class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        int n1_size = nums1.size();
        int n2_size = nums2.size();

        if (nums1.empty()) {
            if (n2_size & 1) {
                return nums2[n2_size >> 1];
            } else {
                int half = n2_size >> 1;

                return (nums2[half - 1] + nums2[half]) / 2.0;
            }
        }

        int first_half_size = (n1_size + n2_size + 1) >> 1;
        int min_n1_contri = 0, max_n1_contri = n1_size;
        double answer = 0.0;

        while (min_n1_contri <= max_n1_contri) {
            int n1_contri = (min_n1_contri + max_n1_contri) >> 1;
            int n2_contri = first_half_size - n1_contri;

            if (n1_contri > 0 && nums1[n1_contri - 1] > nums2[n2_contri]) {
                max_n1_contri = n1_contri - 1;
            } else if (n1_contri < n1_size && nums1[n1_contri] < nums2[n2_contri - 1]) {
                min_n1_contri = n1_contri + 1;
            } else {
                int first_median = 0;

                if (!n1_contri) {
                    first_median = nums2[n2_contri - 1];
                } else if (!n2_contri) {
                    first_median = nums1[n1_contri - 1];
                } else {
                    first_median = max(nums1[n1_contri - 1], nums2[n2_contri - 1]);
                }

                int is_odd = (n1_size + n2_size) & 1;

                if (is_odd) {
                    answer = first_median;
                } else {
                    int second_median = 0;

                    if (n1_contri == n1_size) {
                        second_median = nums2[n2_contri];
                    } else if (n2_contri == n2_size) {
                        second_median = nums1[n1_contri];
                    } else {
                        second_median = min(nums1[n1_contri], nums2[n2_contri]);
                    }

                    answer = (first_median + second_median) / 2.0;
                }

                break;
            }
        }

        return answer;
    }
};
