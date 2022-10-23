<script>
    // @ts-ignore
    import BudgetItem from "$lib/budget-item.svelte";


    const title = "Budget";
</script>

<svelte:head>
    <title>{title}</title>
</svelte:head>

<h1>{title}</h1>

<form action="" method="">
    <input type="text" name="text" value="" aria-label="Add a todo" placeholder=" + tap to add a budget" />
</form>

<BudgetItem />

