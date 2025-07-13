func matchPlayersAndTrainers(players []int, trainers []int) (ans int) {
	sort.Ints(players)
	sort.Ints(trainers)
	m, n := len(players), len(trainers)
	for i, j := 0, 0; i < m && j < n; i++ {
		for j < n && players[i] > trainers[j] {
			j++
		}
		if j < n {
			ans++
			j++
		}
	}
	return
}