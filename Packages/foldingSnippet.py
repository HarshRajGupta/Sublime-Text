import sublime
import sublime_plugin

class ExpandAndFoldSnippetCommand(sublime_plugin.TextCommand):
    def run(self, edit, name, folds):
        self.view.run_command("insert_snippet", {"name": name})

        for _ in range(folds):
            self.view.run_command("fold")
            self.view.run_command("next_field")


class FoldingSnippetEventListener(sublime_plugin.EventListener):
    def on_query_completions(self, view, prefix, locations):
        if not all(view.match_selector(pt, "source.c++") for pt in locations):
            return None

        return [
            sublime.CompletionItem.command_completion(
                "#include <bits/stdc++.h>",
                "expand_and_fold_snippet",
                {
                    "name": "Packages/User/stdc++.sublime-snippet",
                    "folds": 1
                },
                "n RUNs",
                sublime.KIND_SNIPPET,
                details="Multiple Execution Template",
            ), 
            sublime.CompletionItem.command_completion(
                "#include <iostream>",
                "expand_and_fold_snippet",
                {
                    "name": "Packages/User/iostream.sublime-snippet",
                    "folds": 1
                },
                "1 RUN",
                sublime.KIND_SNIPPET,
                details="Single Execution Template",
            ),
            sublime.CompletionItem.command_completion(
                "#include <test>",
                "expand_and_fold_snippet",
                {
                    "name": "Packages/User/solution.sublime-snippet",
                    "folds": 1
                },
                "Solution.test()",
                sublime.KIND_SNIPPET,
                details="OOPS Template",
            )
        ]