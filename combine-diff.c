static int filename_changed(char status)
{
	return status == 'R' || status == 'C';
}

static struct combine_diff_path *intersect_paths(
	struct combine_diff_path *curr,
	int n,
	int num_parent,
	int combined_all_paths)
	int i, j, cmp;

			if (combined_all_paths &&
			    filename_changed(p->parent[n].status)) {
				strbuf_init(&p->parent[n].path, 0);
				strbuf_addstr(&p->parent[n].path,
					      q->queue[i]->one->path);
			}
			for (j = 0; j < num_parent; j++)
				if (combined_all_paths &&
				    filename_changed(p->parent[j].status))
					strbuf_release(&p->parent[j].path);
		if (combined_all_paths &&
		    filename_changed(p->parent[n].status))
			strbuf_addstr(&p->parent[n].path,
				      q->queue[i]->one->path);
static char *grab_blob(struct repository *r,
		       const struct object_id *oid, unsigned int mode,
		*size = fill_textconv(r, textconv, df, &blob);
static void consume_hunk(void *state_,
			 long ob, long on,
			 long nb, long nn,
			 const char *funcline, long funclen)

	state->ob = ob;
	state->on = on;
	state->nb = nb;
	state->nn = nn;
	state->lno = state->nb;
	if (state->nn == 0) {
		/* @@ -X,Y +N,0 @@ removed Y lines
		 * that would have come *after* line N
		 * in the result.  Our lost buckets hang
		 * to the line after the removed lines,
		 *
		 * Note that this is correct even when N == 0,
		 * in which case the hunk removes the first
		 * line in the file.
		 */
		state->lost_bucket = &state->sline[state->nb];
		if (!state->nb)
			state->nb = 1;
	} else {
		state->lost_bucket = &state->sline[state->nb-1];
	if (!state->sline[state->nb-1].p_lno)
		state->sline[state->nb-1].p_lno =
			xcalloc(state->num_parent, sizeof(unsigned long));
	state->sline[state->nb-1].p_lno[state->n] = state->ob;
}

static void consume_line(void *state_, char *line, unsigned long len)
{
	struct combine_diff_state *state = state_;
static void combine_diff(struct repository *r,
			 const struct object_id *parent, unsigned int mode,
	parent_file.ptr = grab_blob(r, parent, mode, &sz, textconv, path);
	if (xdi_diff_outf(&parent_file, result_file, consume_hunk,
			  consume_line, &state, &xpp, &xecfg))
	int abbrev = opt->flags.full_index ? the_hash_algo->hexsz : DEFAULT_ABBREV;
	if (rev->combined_all_paths) {
		for (i = 0; i < num_parent; i++) {
			char *path = filename_changed(elem->parent[i].status)
				? elem->parent[i].path.buf : elem->path;
			if (elem->parent[i].status == DIFF_STATUS_ADDED)
				dump_quoted_path("--- ", "", "/dev/null",
						 line_prefix, c_meta, c_reset);
			else
				dump_quoted_path("--- ", a_prefix, path,
						 line_prefix, c_meta, c_reset);
		}
	} else {
		if (added)
			dump_quoted_path("--- ", "", "/dev/null",
					 line_prefix, c_meta, c_reset);
		else
			dump_quoted_path("--- ", a_prefix, elem->path,
					 line_prefix, c_meta, c_reset);
	}
	userdiff = userdiff_find_by_path(opt->repo->index, elem->path);
		textconv = userdiff_get_textconv(opt->repo, userdiff);
		result = grab_blob(opt->repo, &elem->oid, elem->mode, &result_size,
				result = grab_blob(opt->repo, &elem->oid,
						   elem->mode, &result_size,
						   NULL, NULL);
				result = grab_blob(opt->repo, &oid, elem->mode,
			result_size = fill_textconv(opt->repo, textconv, df, &result);
				if (convert_to_git(rev->diffopt.repo->index,
						   elem->path, result, len, &buf, global_conv_flags_eol)) {
			buf = grab_blob(opt->repo,
					&elem->parent[i].oid,
			if (oideq(&elem->parent[i].oid,
				  &elem->parent[j].oid)) {
			combine_diff(opt->repo,
				     &elem->parent[i].oid,
	for (i = 0; i < num_parent; i++)
		if (rev->combined_all_paths) {
			if (filename_changed(p->parent[i].status))
				write_name_quoted(p->parent[i].path.buf, stdout,
						  inter_name_termination);
			else
				write_name_quoted(p->path, stdout,
						  inter_name_termination);
		}
/*
 * Diff stat formats which we always compute solely against the first parent.
 */
#define STAT_FORMAT_MASK (DIFF_FORMAT_NUMSTAT \
			  | DIFF_FORMAT_SHORTSTAT \
			  | DIFF_FORMAT_SUMMARY \
			  | DIFF_FORMAT_DIRSTAT \
			  | DIFF_FORMAT_DIFFSTAT)
	const struct oid_array *parents,
	struct diff_options *opt,
	int combined_all_paths)
		int stat_opt = output_format & STAT_FORMAT_MASK;
		paths = intersect_paths(paths, i, num_parent,
					combined_all_paths);
		paths = find_paths_generic(oid, parents, &diffopts,
					   rev->combined_all_paths);
		stat_opt = opt->output_format & STAT_FORMAT_MASK;
		else if (opt->output_format & STAT_FORMAT_MASK)
		for (i = 0; i < num_parent; i++)
			if (rev->combined_all_paths &&
			    filename_changed(tmp->parent[i].status))
				strbuf_release(&tmp->parent[i].path);