<script>
    // @ts-ignore
    import BudgetItem from "$lib/budget-item.svelte";

    const title = "Budget";
</script>

<svelte:head>
    <title>{title}</title>
</svelte:head>

<div class="budgets">
    <h1>{title}</h1>
    
    <form action="" method="" class="new">
        <input type="text" name="text" value="" aria-label="Add a todo" placeholder=" + tap to add a budget" />
    </form>
    
    <BudgetItem />
    <BudgetItem />
    <BudgetItem />
</div>

<style>
    .budgets {
        width: 100%;
        max-width: 42rem;
        margin: 4rem auto 0 auto;
    }

    .new {
        margin: 0 0 0.5rem 0;
    }

    .new input {
        font-size: 28px;
        width: 100%;
        padding: 0.5em 1em 0.3em 1em;
        text-align: center;
        background-color: transparent;
    }

    .budgets :global(input) {
        border: 1px solid transparent;
    }

    .budgets :global(input:focus-visible) {
        box-shadow: inset 1px 1px 6px rgba(0, 0, 0, 0.1);
        border: 1px solid #ff3e00 !important;
        outline: none;
    }

</style>

