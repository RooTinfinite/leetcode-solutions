class Solution:
    def findAllRecipes(
        self,
        recipes: list[str],
        ingredients: list[list[str]],
        supplies: list[str],
    ) -> list[str]:
        # Track available ingredients and recipes
        available = set(supplies)

        # Queue to process recipe indices
        recipe_queue = deque(range(len(recipes)))
        created_recipes = []
        last_size = -1  # Tracks last known available count

        # Continue while we keep finding new recipes
        while len(available) > last_size:
            last_size = len(available)
            queue_size = len(recipe_queue)

            # Process all recipes in current queue
            while queue_size > 0:
                queue_size -= 1
                recipe_idx = recipe_queue.popleft()
                if all(
                    ingredient in available
                    for ingredient in ingredients[recipe_idx]
                ):
                    # Recipe can be created - add to available items
                    available.add(recipes[recipe_idx])
                    created_recipes.append(recipes[recipe_idx])
                else:
                    recipe_queue.append(recipe_idx)

        return created_recipes