import flet as ft
import time


def demo1(page: ft.Page):
    t = ft.Text(value="Hello, Flet!", color="green")
    page.add(t)

    for i in range(10):
        t.value = f"Step {i}"
        page.update()
        time.sleep(1)

def demo2(page: ft.Page):
    row = ft.Row(controls=[ft.Text("A"), ft.Text("B"), ft.Text("C")])
    page.add(row)
    row = ft.Row(controls=[
        ft.TextField(label="Your name"),
        ft.ElevatedButton(text="Say my name!")
    ])
    page.add(row)

def demo3(page):
    def add_clicked(e):
        page.add(ft.Checkbox(label=new_task.value))
        new_task.value = ""
        new_task.focus()
        new_task.update()
    
    new_task = ft.TextField(hint_text="What's needs to be done?", width=300)
    page.add(ft.Row([new_task, ft.ElevatedButton("Add", on_click=add_clicked)]))

def counter(page: ft.Page):
    page.title = "Flet counter example"
    page.vertical_alignment = ft.MainAxisAlignment.CENTER

    txt_number = ft.TextField(value="0", text_align="right", width=100)

    def minus_click(e):
        txt_number.value = str(int(txt_number.value) - 1)
        page.update()

    def plus_click(e):
        txt_number.value = str(int(txt_number.value) + 1)
        page.update()
    
    page.add(
        ft.Row(
            [
                ft.IconButton(ft.icons.REMOVE, on_click=minus_click),
                txt_number,
                ft.IconButton(ft.icons.ADD, on_click=plus_click),
            ],
            alignment=ft.MainAxisAlignment.CENTER,
        )
    )

def demo_textbox(page : ft.Page):
    txt_name = ft.TextField(label="Your name")
    def btn_click(e):
        if not txt_name.value:
            txt_name.error_text = "Please enter your name"
            page.update()
        else:
            name = txt_name.value
            page.clean()
            page.add(ft.Text(f"Hello, {name}"))

    page.add(txt_name, ft.ElevatedButton("Say Hello!", on_click=btn_click))

def demo_checkbox(page: ft.Page):
    output_text = ft.Text()

    def checkbox_changed(e):
        output_text.value = f"You have learned how to ski: {todo_check.value}."
        page.update()

    todo_check = ft.Checkbox(label="ToDo: Learn how to use ski", value=False, on_change=checkbox_changed)
    page.add(todo_check, output_text)

def demo_dropdown(page: ft.Page):
    output_text = ft.Text()
    color_dropdown = ft.Dropdown(width=100, options=[ft.dropdown.Option("Red"), ft.dropdown.Option("Green"), ft.dropdown.Option("Blue")])
    def button_clicked(e):
        output_text.value = f"Dropdown value is: {color_dropdown.value}"
        page.update()
    submit_btn = ft.ElevatedButton(text="Submit", on_click=button_clicked)
    page.add(color_dropdown, submit_btn, output_text)



ft.app(target=demo_dropdown)


