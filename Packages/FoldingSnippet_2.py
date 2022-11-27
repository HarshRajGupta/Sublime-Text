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
                "#include<iostream>",
                "expand_and_fold_snippet",
                {
                    "name": "Packages/User/custom_snippet_2.sublime-snippet",
                    "folds": 2
                },
                "1 RUN",
                sublime.KIND_SNIPPET,
                details="Comp. Prog. Template for Single testCase",
            )
        ]