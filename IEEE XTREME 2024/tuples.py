def count_valid_assignments(N, M, constraints):
    MOD = 998244353
    valid_count = 0
    infinite = False

    # Check if any variable can take unbounded values
    involved_indices = set()
    
    for low, high, K, *indices in constraints:
        involved_indices.update(indices)

    # If there are variables not involved in any constraints, infinite solutions exist
    if len(involved_indices) < N:
        return "infinity"

    # A function to check if a specific assignment satisfies all constraints
    def satisfies_constraints(V):
        for low, high, K, *indices in constraints:
            subset_sum = sum(V[idx - 1] for idx in indices)  # Convert 1-based to 0-based index
            if not (low <= subset_sum <= high):
                return False
        return True

   
    max_value = 100  # This is an arbitrary limit for practical brute-force search

    for V1 in range(max_value + 1):
        for V2 in range(max_value + 1):
            for V3 in range(max_value + 1):
                # Create a list of current values
                V = [V1, V2, V3][:N]  # Adjust according to N

                if satisfies_constraints(V):
                    valid_count += 1

    return valid_count % MOD

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    # Read N and M
    N, M = map(int, data[0].split())
    constraints = []

    for i in range(1, M + 1):
        parts = list(map(int, data[i].split()))
        low, high, K = parts[0], parts[1], parts[2]
        indices = parts[3:3 + K]
        constraints.append((low, high, K, *indices))

    # Count valid assignments
    result = count_valid_assignments(N, M, constraints)

    # Print the result
    print(result)

if __name__ == "__main__":
    main()